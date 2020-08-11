/* 
 * File:   Figure.h
 * Author: dvdemon
 *
 * Created on August 30, 2015, 6:33 PM
 */

#ifndef FIGURE_HPP
#define	FIGURE_HPP

class Figure {
public:
    virtual double Square() = 0;
    virtual void   Print() = 0;
    virtual ~Figure() {};
};

#endif	/* FIGURE_H */

