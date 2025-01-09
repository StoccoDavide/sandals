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

#ifndef SANDALS_RKF45_HXX
#define SANDALS_RKF45_HXX

namespace Sandals
{
  //! Butcher tableau for the Runge-Kutta-Fehlberg 4(5) method:
  //!
  //! \f[
  //! \begin{array}{c|cccccc}
  //!         0 &         0 &          0 &          0 &           0 &      0 &    0 \\
  //!       1/4 &       1/4 &          0 &          0 &           0 &      0 &    0 \\
  //!       3/8 &      3/32 &       9/32 &          0 &           0 &      0 &    0 \\
  //!     12/13 & 1932/2197 & -7200/2197 &  7296/2197 &           0 &      0 &    0 \\
  //!         1 &   439/216 &         -8 &   3680/513 &   -845/4104 &      0 &    0 \\
  //!       1/2 &     -8/27 &          2 & -3544/2565 &   1859/4104 & -11/40 &    0 \\
  //!   \hline
  //!           &    16/135 &          0 & 6656/12825 & 28561/56430 &  -9/50 & 2/55 \\
  //!           &    25/216 &          0 & 1408/2565  & 2197/4104   &  -1/5  &    0 \\
  //! \end{array} \text{.}
  //! \f]
  class RKF45Tableau : public Tableau<6>
  {
    public:
    using Tableau<6>::Type;   //!< Runge-Kutta type enumeration.
    using Tableau<6>::Vector; //!< Templetized vector type.
    using Tableau<6>::Matrix; //!< Templetized matrix type.

    //! Class constructor for the Runge-Kutta-Fehlberg 4(5) method.
    RKF45Tableau() {
      this->name        = "RKF45";
      this->type        = Type::ERK;
      this->order       = 4;
      this->order_e     = 5;
      this->is_embedded = true;
      this->A   << 0.0,           0.0,            0.0,            0.0,           0.0,        0.0,
                   1.0/4.0,       0.0,            0.0,            0.0,           0.0,        0.0,
                   3.0/32.0,      9.0/32.0,       0.0,            0.0,           0.0,        0.0,
                   1932.0/2197.0, -7200.0/2197.0, 7296.0/2197.0,  0.0,           0.0,        0.0,
                   439.0/216.0,   -8.0,           3680.0/513.0,   -845.0/4104.0, 0.0,        0.0,
                   -8.0/27.0,     2.0,            -3544.0/2565.0, 1859.0/4104.0, -11.0/40.0, 0.0;
      this->b   << 25.0/216.0, 0.0,     1408.0/2565.0,  2197.0/4104.0,   -1.0/5.0,  0.0;
      this->b_e << 16.0/135.0, 0.0,     6656.0/12825.0, 28561.0/56430.0, -9.0/50.0, 2.0/55.0;
      this->c   << 0.0,        1.0/4.0, 3.0/8.0,        12.0/13.0,       1.0,       1.0/2.0;
    }
  }; // class RKF45Tableau

  //! Class container for the Runge-Kutta-Fehlberg 4(5) method.
  template <Size N>
  class RKF45 : public RungeKutta<6, N>
  {
  public:
    using System = typename Implicit<N>::Pointer; //!< System type.

    //! Class constructor for a Runge-Kutta-Fehlberg 4(5) solver given a Tableau reference.
    //! \param[in] t_tableau The Tableau reference.
    RKF45() : RungeKutta<6, N>(RKF45Tableau()) {}

    //! Class constructor for a Runge-Kutta-Fehlberg 4(5) solver given a Tableau reference.
    //! \param[in] t_tableau The Tableau reference.
    //! \param[in] t_system The system reference.
    RKF45(System t_system) : RungeKutta<6, N>(RKF45Tableau(), t_system) {}

  }; // class RKF45

} // namespace Sandals

#endif // SANDALS_RKF45_HXX
