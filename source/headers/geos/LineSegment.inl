/**********************************************************************
 * $Id$
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2005-2006 Refractions Research Inc.
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 **********************************************************************/

#ifndef GEOS_LINESEGMENT_INL
#define GEOS_LINESEGMENT_INL

#include <cassert>
#include <geos/geosAlgorithm.h>

namespace geos {

INLINE
LineSegment::LineSegment(const LineSegment& ls)
	:
	p0(ls.p0),
	p1(ls.p1)
{
}

INLINE
LineSegment::LineSegment(const Coordinate& c0, const Coordinate& c1)
	:
	p0(c0),
	p1(c1)
{
}

INLINE
LineSegment::LineSegment()
{
}

INLINE
LineSegment::~LineSegment()
{
}

INLINE double
LineSegment::distancePerpendicular(const Coordinate& p) const
{
	return algorithm::CGAlgorithms::distancePointLinePerpendicular(p, p0, p1);
}

INLINE void
LineSegment::setCoordinates(const Coordinate& c0, const Coordinate& c1)
{
	p0=c0; p1=c1;
}

INLINE const Coordinate&
LineSegment::getCoordinate(unsigned int i) const
{
	if (i==0) return p0;
	assert(i==1);
	return p1;
}

INLINE void
LineSegment::setCoordinates(const LineSegment& ls)
{
	setCoordinates(ls.p0,ls.p1);
}

INLINE double
LineSegment::getLength() const
{
	return p0.distance(p1);
}

INLINE bool
LineSegment::isHorizontal() const
{
	return p0.y == p1.y;
}

INLINE bool
LineSegment::isVertical() const
{
	return p0.x == p1.x;
}

INLINE int
LineSegment::orientationIndex(const LineSegment* seg) const
{
	assert(seg);
	return orientationIndex(*seg);
}

INLINE CoordinateSequence*
LineSegment::closestPoints(const LineSegment* line)
{
	assert(line);
	return closestPoints(*line);
}

INLINE ostream&
operator<< (ostream& o, const LineSegment& l) {
	return o<<"LINESTRING("<<l.p0.x<<" "<<l.p0.y<<","<<l.p1.x<<" "<<l.p1.y<<")";
}



} // namespace geos

#endif // GEOS_LINESEGMENT_INL