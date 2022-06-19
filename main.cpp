#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <iostream>
#include <CGAL/Triangle_2.h>
#include <CGAL/Kernel/global_functions.h>
#include <CGAL/enum.h>
#include <CGAL/Vector_3.h>
#include "functional"
#include "string.h"
#include <CGAL/intersections.h>
#include <CGAL/Line_2.h>
#include <CGAL/Triangle_2.h>
#include <boost/optional/optional_io.hpp>


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point;
typedef CGAL::Polygon_2<K> Polygon_2;
typedef CGAL::Vector_3<K> vec;
using std::cout; using std::endl;
typedef CGAL::Triangle_2<K> tAngle;
typedef CGAL::Angle angle;
typedef K::FT number_t;

typedef K::Point_2 Point_2;
typedef K::Segment_2 Segment_2;
typedef K::Triangle_2 Triangle_2;
typedef K::Line_2 Line_2;
typedef K::Intersect_2 Intersect_2;

const number_t PI = M_PI;

template<class Point_2>
inline number_t getAngle(const Point_2 &a, const Point_2 &b, const Point_2 &c) {
            auto ab = b-a,
            ac = c - a;

            number_t res = ab.x()*ac.y() - ab.y()*ac.x();

            //cout<<"res "<<res<<endl;
    //number_t result = atan2(pq.y(), pq.x()) - atan2(rq.y(), rq.x());

    // atan() returns a value between -PI and PI. From zero ("up"), CCW rotation is negative and CW is positive.
    // Our zero is also "up," but we only want positive values between 0 and 2*PI:

    //cout<<PI<<endl;
    //result = fmod(result + 2 * PI, 2 * PI);

        //cout<<p<<" - "<<q<<" - "<<r<<endl;
        //cout<<"angle="<<result<<endl;
    return res;
}

//bool is()
//{
//    bool hasEar = true;
//    for( unsigned  j = 0; j<verticesOfP.size(); j++ )
//    {
//        if( j == vertexA || j == vertexB || j == vertexC ) continue;
//        Point inside = verticesOfP.at(j);
//        if(pointInTraingle(inside,verticesOfP.at(vertexA),verticesOfP.at(vertexB),verticesOfP.at(vertexC)))
//        {
//            hasEar = false;
//            break;
//        }
//    }
//    if( hasEar )
//    {
//        traingle.emplace_back(verticesOfP.at(vertexB));
//        traingle.emplace_back(verticesOfP.at(vertexA));
//        traingle.emplace_back(verticesOfP.at(vertexC));
//
//        indexList.erase(indexList.begin()+i);
//        std::cout<<i<<std::endl;
//        std::cout<<vertexA<<" "<<vertexB<<" "<<vertexC<<std::endl;
//
//        diagonals.emplace_back(std::make_pair(vertexB,vertexC));
//    }
//}
//}


int main()
{
    Point points[] = { Point(0,0),Point(1,0), Point(0.5,0.5), };
    Polygon_2 pgn(points, points+3);

    if( pgn.is_counterclockwise_oriented() )
    {
        std::cout<<"CCW"<<std::endl;
    }
    else
    {
        std::cout<<"CW"<<std::endl;
    }

    tAngle t(Point(-2,1), Point(-5,5), Point(4,1));
    // check if the polygon is simple.
//    cout << "The polygon is " <<
//         (pgn.is_simple() ? "" : "not ") << "simple." << endl;
//    // check if the polygon is convex
//    cout << "The polygon is " <<
//         (pgn.is_convex() ? "" : "not ") << "convex." << endl;
//    cout<< t.area()<<endl;
//    cout<<t.orientation()<<endl;
//    angle an;
    double ang = CGAL::orientation(Point(-3,6),Point(0,1),Point(4,4));
    auto ab = Point(0,1) - Point(-3,4);
    auto ac = Point(0,1) - Point(4,4);

    cout<<"angle "<< ( CGAL::left_turn(Point(1,0),Point( 0.5,0.5),Point(0,0)))<<std::endl;
    //cout<<"ang "<<ang<<endl;
//    if( ang == -1 )
//    {
//        ang = getAngle(Point(-3,6),Point(0,1),Point(4,4));
//        cout<<ang<<endl;
//    }
    //cout<<CGAL::angle(Point(-10,1), Point(-5,6), Point(4,1))<<endl;

//    Point p(0,0);
//    Point q(1,0);
//
//    CGAL::Line_2<K> line1(p,q), line2(Point(0,0),Point(0,0));
//
//
//    //std::cout<<"line "<<CGAL::do_intersect(line1,line2)<<std::endl;
//
//    Segment_2 seg(Point_2(0,0), Point_2(2,2));
//    Segment_2 seg1(Point_2(2,0), Point_2(0,-1));
//
//
//    //Line_2 lin(1,-1,0);
//    const auto result = intersection(seg, seg1);
//    if (result) {
//        if (const Segment_2* s = boost::get<Segment_2>(&*result)) {
//            std::cout << *s << std::endl;
//        } else {
//            const Point_2* p = boost::get<Point_2 >(&*result);
//            std::cout << *p << std::endl;
//        }
//    }
//    else
//    {
//        std::cout<<"no inter"<<std::endl;
//    }
//
//
//
    Triangle_2 tri1(Point(1,2) ,Point(3,4),Point(1,6));
    Triangle_2 tri2(Point(3,4) ,Point(7,8),Point(5,7));
    Triangle_2 tri3(Point(3,4) ,Point(7,8),Point(8,5));
    Triangle_2 tri4(Point(1,2) ,Point(-2,4),Point(1,6));

    auto resTriangle = intersection(tri1,tri4);

    if( resTriangle )
    {
        if (const Segment_2* s = boost::get<Segment_2>(&*resTriangle)) {
            std::cout <<"s "<< *s << std::endl;
        } else {
            const Point_2* p = boost::get<Point_2 >(&*resTriangle);
            std::cout <<"p "<< *p << std::endl;
        }
        std::cout<<"triangle intersect "<<std::endl;
    }
    else
    {
        std::cout<<"Not intersect"<<std::endl;
    }

    return 0;
}