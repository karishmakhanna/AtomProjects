/*
    This code was written to support the book, "ARM Assembly for Embedded Applications",
    by Daniel W. Lewis. Permission is granted to freely share this software provided
    that this notice is not removed. This software is intended to be used with a run-time
    library adapted by the author from the STM Cube Library for the 32F429IDISCOVERY
    board and available for download from http://www.engr.scu.edu/~dlewis/book3.
*/
        .syntax         unified
        .cpu            cortex-m4
        .text

// float EccentricAnomaly(float e, float M)

        .global         EccentricAnomaly
        .thumb_func
        .align
EccentricAnomaly:    // S0 = e, S1 = M
        PUSH            {LR}                // preserve LR
        VPUSH           {S16,S17}           // preserve S16,S17
        VMOV            S16,S0              // S16 -> e
        VMOV            S17,S1              // S17 -> M
        VMOV            S0,S1               // S0 -> M
        BL              cosDeg              // S0 -> cosDeg(M)
        VMOV            S1,1.0              // S1 -> 1.0
        VMLA.F32        S1,S16,S0           // S1 -> 1.0 + e * cosDeg(M)
        VMUL.F32        S16,S16,S1          // S16 -> e * (1.0 + e * cosDeg(M))
        VMOV            S0,S17              // S0 -> M
        BL              sinDeg              // S0 -> sinDeg(M)
        VMUL.F32        S0,S0,S16           // S0 -> e * sinDeg(M) * (1.0 + e * cosDeg(M))
        BL              Rad2Deg             // S0 -> Rad2Deg(e * sinDeg(M) * (1.0 + e * cosDeg(M)))
        VADD.F32        S0,S0,S17           // S0 -> M + Rad2Deg(e * sinDeg(M) * (1.0 + e * cosDeg(M)))
        VPOP            {S16,S17}           // restore S16,S17
        POP             {PC}                // restore LR and return S0


// float Kepler(float m, float ecc)

        .global         Kepler
        .thumb_func
        .align
Kepler:    // S0 = m, S1 = ecc
        PUSH            {LR}                // preserve LR
        VPUSH           {S16,S17,S18,S19}   // preserve S16,S17,S18,S19
        VMOV            S16,S0              // S16 -> m
        VMOV            S17,S1              // S17 -> ecc
        BL              Deg2Rad             // S0 -> Deg2Rad(m)
        VMOV            S18,S0              // S18 -> e = Deg2Rad(m)
        VMOV            S19,S0              // S19 -> m = Deg2Rad(m)
L1:     BL              sinDeg              // S0 -> sinf(e)
        VMUL.F32        S0,S0,S17           // S0 -> ecc * sinf(e)
        VSUB.F32        S0,S18,S0           // S0 -> e - ecc * sinf(e)
        VSUB.F32        S19,S0,S16          // S19 -> delta = e - ecc * sinf(e) - m
        VMOV            S0,S18              // S0 -> e
        BL              cosDeg              // S0 -> cosf(e)
        VMUL.F32        S0,S0,S17           // S0 -> ecc * cosf(e)
        VMOV            S1,1.0              // S1 -> 1.0
        VSUB.F32        S0,S1,S0            // S0 -> 1.0 - ecc * cosf(e)
        VDIV.F32        S0,S19,S0           // S0 -> delta / (1.0 - ecc * cosf(e))
        VSUB.F32        S18,S18,S0          // S18 -> e = e - delta / (1.0 - ecc * cosf(e))
        VMOV            S0,S18              // S0 -> e
        VABS.F32        S1,S19              // S1 -> fabsf(delta)
        VLDR            S2,epsilon          // S2 -> epsilon = 1E-6
        VCMP.F32        S2,S1               // S2<S1?
        VMRS            APSR_nzcv,FPSCR     // change FPU flags
        BGE             L2                  // if S2>=S1, then go to L2
        BL              L1                  // else if S2<S1, then go to L1
L2:     VPOP            {S16,S17,S18,S19}   // restore S16,S17,S18,S19
        POP             {PC}                // restore LR and return S0 = e

        .align
epsilon:
        .float          1E-6

        .end
