from datetime import datetime
from slugify import slugify

from typing import TYPE_CHECKING
if TYPE_CHECKING:
    from cptk.scrape import Problem
    problem: 'Problem' = None


def generate_name(problem: 'Problem') -> str:
    name = problem.name
    if hasattr(problem, 'mark') and problem.mark is not None:
        name = f'{problem.mark}-{name}'
    return slugify(name)


def generate_path(problem: 'Problem') -> str:
    path = [slugify(problem.website.name)]

    if problem.contest is not None:
        path.append(slugify(problem.contest.name))

    if hasattr(problem, 'section') and problem.section is not None:
        path.append(slugify(problem.section))

    path.append(generate_name(problem))

    return '/'.join(path)


now = datetime.now()
path = generate_path(problem)
name = generate_name(problem)

__all__ = ['problem', 'now', 'path', 'name']
