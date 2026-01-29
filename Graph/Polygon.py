from Helpers.Point import Point
from Helpers.SpacialReasoning import *

class Polygon:
    def __init__(self, points: list[Point]):
        self.points = points

    def findPotentialTriangle(self,point: Point) -> list[Point]:
        if len(self.points) < 3:
            return None
        
        left: int = 1
        right: int = len(self.points) - 1

        while left <= right:
            middle: int = (left + right) // 2
            if isLeftTurn(self.points[0], self.points[middle], point):
                right = middle - 1
            elif isRightTurn(self.points[0], self.points[middle + 1], point):
                left = middle + 1
            else:
                return [self.points[0], self.points[middle], self.points[middle + 1]] 

        return None


    def contains(self, point: Point) -> bool:
        """
        checks if the given point lies within the Polygon. Assumes that the polygon is Convex!
        
        :param point: the Point to check
        :return: True if point is within the polygon or exactly on it's bounds, false otherwise
        :rtype: bool
        """
        triangle: list[Point] = self.findPotentialTriangle(point)
        if triangle == None:
            return False
        
        return isInsideTriangle(point, triangle)


def main():
    P = Polygon([Point(0,0), Point(0,1), Point(1,1), Point(1,0)])
    if (P.contains(Point(0, 1))):
        print("contained")
    else:
        print("not contained")

main()