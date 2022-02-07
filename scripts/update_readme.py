from __future__ import annotations

import os
import json
from glob import glob
from typing import List, NamedTuple
from urllib.parse import urlencode

import jinja2

ME = os.path.realpath(__file__)
HERE = os.path.dirname(ME)
ROOT = os.path.dirname(HERE)
README_TEMPLATE = os.path.join(HERE, 'README_TEMPLATE.md')
README_OUTPUT = os.path.join(ROOT, 'README.md')
SEARCH_EXCLUDE_DIRS = ['scripts', '.cptk', '.git', '.github']
SEARCH_FILES = ['*.cpp', '*.cc', '*.c', '*.py']  # TODO: change to cptk recipe

COLORS = [
    '#0094C6',
    '#13C4A3',
    '#4BC0C0',
    '#005E7C',
    '#84DD63',
    '#36F1CD',
    '#B0FE76'
]


def chart_url(
    data: dict,
    width: int,
    height: int,
    background: str = 'transparent',
    format: str = 'SVG',
) -> str:
    """ Converts the given chart data into a URL that contains the chart as an
    image. Uses https://quickchart.io/ """

    params = {
        'width': width,
        'height': height,
        'bkg': background,
        'f': format,
        'chart': json.dumps(data),
    }

    return f'https://quickchart.io/chart?{urlencode(params)}'


class Folder(NamedTuple):
    name: str
    recipes: List[str]


def load_folders_data(root: str) -> list[Folder]:
    dirs = [
        (dir, os.path.join(root, dir))
        for dir in os.listdir(root)
        if os.path.isdir(os.path.join(root, dir))
        and dir not in SEARCH_EXCLUDE_DIRS
    ]

    data = [
        Folder(
            name=name,
            recipes=[
                recipe
                for fileglob in SEARCH_FILES
                for recipe in glob(f'{fullpath}/**/{fileglob}', recursive=True)
            ],
        )
        for name, fullpath in dirs
    ]

    data.sort(key=lambda folder: len(folder.recipes), reverse=True)
    return [d for d in data if len(d.recipes)]


def folders_pie_data(data: list[Folder], colors: list[str]) -> dict:
    LABEL_COLOR = 'white'
    TITLE_COLOR = '#aaa'

    return {
        'type': 'outlabeledDoughnut',
        'data': {
            'labels': [d.name for d in data],
            'datasets': [{
                'backgroundColor': colors,
                'data': [len(d.recipes) for d in data],
            }]
        },
        'options': {
            'plugins': {
                'legend': False,
                'outlabels': {
                    'text': '%l (%v)',
                    'color': LABEL_COLOR,
                    'stretch': 35,
                    'borderWidth': 2,
                    'borderRadius': 10,
                    'textAlign': 'center',
                    'font': {
                        'style': 'bold',
                        'resizable': True,
                        'minSize': 8,
                        'maxSize': 20,
                    }
                },
                'doughnutlabel': {
                    'labels': [
                        {
                            'text': sum(len(d.recipes) for d in data),
                            'color': TITLE_COLOR,
                            'font': {'size': 20, 'weight': 'bold'},
                        },
                        {
                            'text': 'problems',
                            'font': {'size': 12},
                            'color': TITLE_COLOR,
                        },
                        {
                            'text': 'solved',
                            'font': {'size': 12},
                            'color': TITLE_COLOR,
                        },
                    ]
                }
            }
        }
    }


def create_jinja_env():
    folders_data = load_folders_data(ROOT)
    chart_data = folders_pie_data(folders_data, COLORS[:len(folders_data)])

    env = jinja2.Environment()

    env.globals.update({
        'foldersData': folders_data,
        'foldersPieUrl': chart_url(chart_data, width=500, height=500),
        'problemsCount': sum(len(folder.recipes) for folder in folders_data),
    })

    env.filters.update({
        'percentage': lambda ratio: f'{ratio*100:.0f}%',
    })

    return env


def main(template: str, result: str):
    env = create_jinja_env()
    with open(template, 'r') as f:
        template = f.read()
    parsed = env.from_string(template).render()
    with open(result, 'w') as f:
        f.write(parsed)


if __name__ == '__main__':
    main(README_TEMPLATE, README_OUTPUT)
