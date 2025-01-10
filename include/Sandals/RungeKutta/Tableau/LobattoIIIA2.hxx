/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * Copyright (c) 2025, Davide Stocco and Enrico Bertolazzi.                  *
 *                                                                           *
 * The Sandals project is distributed under the GNU GPLv3.                   *
 *                                                                           *
 * Davide Stocco                                           Enrico Bertolazzi *
 * University of Trento                                 University of Trento *
 * e-mail: davide.stocco@unitn.it         e-mail: enrico.bertolazzi@unitn.it *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

#ifndef SANDALS_LOBATTOIIIA2_HXX
#define SANDALS_LOBATTOIIIA2_HXX

namespace Sandals
{
  //! \brief Butcher tableau for the Lobatto IIIA order 2 method.
  //!
  //! Butcher tableau for the Lobatto IIIA order 2 method:
  //!
  //! \f[
  //! \begin{array}{c|cc}
  //!   1/3 & 5/12 & -1/12 \\
  //!     1 &  3/4 &   1/4 \\
  //!   \hline
  //!       &  3/4 &   1/4
  //! \end{array} \text{.}
  //! \f]
  class LobattoIIIA2Tableau : public Tableau<2>
  {
    public:
    using Tableau<2>::Type;   //!< Runge-Kutta type enumeration.
    using Tableau<2>::Vector; //!< Templetized vector type.
    using Tableau<2>::Matrix; //!< Templetized matrix type.

    //! Class constructor for the Lobatto IIIA order 2 method.
    LobattoIIIA2Tableau() {
      this->name  = "LobattoIIIA2";
      this->type  = Type::DIRK;
      this->order = 2;
      this->A << 0.0,      0.0,
                 1.0/2.0,  1.0/2.0;
      this->b << 1.0/2.0, 1.0/2.0;
      this->c << 0.0,     1.0;
    }
  }; // class LobattoIIIA2Tableau

  //! Class container for the Lobatto IIIA order 2 method.
  template <Size N>
  class LobattoIIIA2 : public RungeKutta<2, N>
  {
  public:
    using System = typename Implicit<N>::Pointer; //!< System type.

    //! Class constructor for a Lobatto IIIA order 2 solver given a Tableau reference.
    //!
    LobattoIIIA2() : RungeKutta<2, N>(LobattoIIIA2Tableau()) {}

    //! Class constructor for a Lobatto IIIA order 2 solver given a Tableau reference.
    //! \param[in] t_system The system reference.
    LobattoIIIA2(System t_system) : RungeKutta<2, N>(LobattoIIIA2Tableau(), t_system) {}

  }; // class LobattoIIIA2

} // namespace Sandals

#endif // SANDALS_LOBATTOIIIA2_HXX
