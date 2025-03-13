class Point:
    def __init__(self,x,y):
        """
        (Point, int, int)->NoneType
        >>> p=Point(1,3)
        >>> p.x 
        1
        >>> p.y
        3
        """
        self.x=x # x좌표
        self.y=y # y좌표

class LineSegment:
    def __init__(self,point1,point2):
        """(LineSegment,Point,Point)->NoneType
        A new LineSegment connecting point1 to point2
        >>> p1=Point(1,3)
        >>> p2=Point(3,2)
        >>> segment=LineSegment(p1,p2)
        >>> segment.startpoint==p1
        True
        >>> segment.endpoint==p2
        True
        """
        self.startpoint=point1
        self.endpoint=point2

    def slope(self):
        """
        (LineSegment)->float
        >>> segment=LineSegment(Point(1,1),Point(3,2))
        >>> segment.slope()
        0.5
        """
        # Write your code below
        return (self.startpoint.y - self.endpoint.y) / (self.startpoint.x - self.endpoint.x)

    def length(self):
        """
        (LineSegment)->float
        >>> segment=LineSegment(Point(1,1),Point(3,2))
        >>> segment.length()
        2.23606797749979
        """
        # Write your code below
        k = ((self.startpoint.y - self.endpoint.y)**2) + ((self.startpoint.x - self.endpoint.x)**2)
        return k **0.5
