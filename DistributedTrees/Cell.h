/*
 * File:   Cell.h
 * Author: Sygram
 *
 * Class: rdf::Cell
 * Needs revision: Yes
 * Description: This class is used as the pure abstract Cell class. All cell
 * classes inherit from this one. Details need to be consulted with the
 * coordinator.
 *
 */

#ifndef CELL_H
#define CELL_H

/**********REQUIRES FURTHER IMPLEMENTATION********/

namespace rdf {

  class Cell {
  public:
    Cell();
    Cell(const Cell& orig);
    // virtual void Reduce(const Cell& other) = 0; //FIXME
    virtual ~Cell();
  private:

  };

} /* rdf */

#endif /* CELL_H */
