#include <math.h>
#include <stdio.h>

#define real double

// Solar constant W / m ^ 2
#define S0 1370

// Stefan - Boltzmann constant W / m2 / K4
#define SIGMA 0.00000005670367

// Temperature inertia (in years)
#define THETA 100.0

// Albedo, in this simulation albedo is considered constant
// in reality albedo can become lower with increased temperatures
// due to ice cap melting
#define ALBEDO 0.33

// Initial values

// Simulation starts in 2007
static const real t0 = 2007.0;
// Temperaturature in 2007 in K
static const real T0 = 288.45;
// CO2 concentration in 2007 in ppm
static const real CO20 = 370.0;

// Greenhouse gaz fraction
static real G(real T, real co2)
{
    return 3.35071874e-03 * T + 3.20986702e-05 * co2 - 0.561593690144655;
}

/*Variation de la température*/
// question 1
real P_in(void){
    return (1-ALBEDO)*S0/4;
}

real P_out(real t, real T){
    return (1-G(t,T))*SIGMA*(T0*T0*T0*T0);
    
}


// question 2
real F(real t,real T){
    return (P_in()-P_out(t0,T0))/100;
}


/*Integration temporelle*/
//question1: On l'a fait manuellement

//question 2


real euler(real t_final,int steps){
    real T_app[steps];
    real t[steps];
    //initialisation:
    T_app[0]=T0;
    t[0]=t0;
    int h=(t_final-t0)/steps;  //le pas

    for(int i=0;i<steps;i++){
        t[i]=t0+i*h;
        T_app[i+1]=T_app[i]+h*F(t[i],T_app[i]);
    }
    //question 3
    for(int i=0;i<steps;i++){
        printf("Itération = %d",i);
        printf("    ");
        printf("Year = %f",t[i]);
        printf("   ");
        printf("Temperature = %f",T_app[i]);
        printf("  ");   
        printf("\n");
    }
    
    return 0;  
    }
    //question 4: voir output.dat et courbe.pdf


int main(int argc, char **argv)
{
    printf("Simple climate simulation\n");
    printf("\n");
    printf("la puissance entrante est :%f", P_in());
    printf("\n");
    printf("La puissance sortante est:%f", P_out(t0, T0));
    printf("\n");
    printf("La différence de la temperature est égale à : %f", F(t0, T0));
    printf("\n");
    printf("la température approximative à chaque instant t est : %f", euler(t_final, steps));
    
    //question 3
    euler(t_final,steps);

    return 0;
}
