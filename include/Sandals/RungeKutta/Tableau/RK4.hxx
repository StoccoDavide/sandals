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

#ifndef SANDALS_RK4_HXX
#define SANDALS_RK4_HXX

namespace Sandals
{

  //! Butcher tableau for the Runge-Kutta 4 method:
  //!
  //! \f[
  //! \begin{array}{c|cccc}
  //!     0 &   0 &   0 &   0 &   0 \\
  //!   1/2 & 1/2 &   0 &   0 &   0 \\
  //!   1/2 &   0 & 1/2 &   0 &   0 \\
  //!     1 &   0 &   0 &   1 &   0 \\
  //!   \hline
  //!       & 1/6 & 1/3 & 1/3 & 1/6
  //! \end{array} \text{.}
  //! \f]
  class RK4Tableau : public Tableau<4>
  {
    public:
    //! Class constructor for the RK4 method.
    RK4Tableau(void) {
      this->name        = "RK4";
      this->order       = 4;
      this->is_embedded = false;
      this->A << 0.0, 0.0, 0.0, 0.0,
                 1/2, 0.0, 0.0, 0.0,
                 0.0, 1/2, 0.0, 0.0,
                 0.0, 0.0, 1.0, 0.0;
      this->b << 1/6, 1/3, 1/3, 1/6;
      this->b_e << NAN_VEC4;
      this->c << 0.0, 1/2, 1/2, 1.0;
    }
  }; // class RK4Tableau

  //! Class container for the Runge-Kutta 4 method.
  template <unsigned N>
  class RK4 : public RungeKutta<4, N>
  {
  public:
    //! Class constructor for the RK4 method.
    RK4(void) : RungeKutta<4, N>(RK4Tableau()) {}
  }; // class RK4

} // namespace Sandals

#endif // SANDALS_RK4_HXX
