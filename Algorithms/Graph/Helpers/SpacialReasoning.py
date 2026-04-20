from Point import Point

def orientationTest(a: Point, b: Point, c: Point) -> int:
    return (
        (b.x * c.y - b.y * c.x)
        - (a.x * c.y - a.y * c.x)
        + (a.x * b.y - a.y * b.x)
    )

def isLeftTurn(a: Point, b: Point, c: Point) -> bool:
    return orientationTest(a, b, c) > 0

def isRightTurn(a: Point, b: Point, c: Point) -> bool:
    return orientationTest(a, b, c) < 0

def isInsideTriangle(point: Point, triangle: list[Point]) -> bool:
    if isLeftTurn(triangle[0], triangle[1], point):
        return False

    if isLeftTurn(triangle[1], triangle[2], point):
        return False

    if isLeftTurn(triangle[2], triangle[0], point):
        return False

    return True 