/* Name: Elizabeth Chan
   Email: lmchan@brynmawr.edu
   Class: cs287: High Performance Scientific Computing
   Description: The following program simulates dart throwing using a random
   number generator (Marsaglia polar method). Variables considered to affect
   accuracy and score are as followed: target location (angle and radius),
   skill level and the number of darts thrown
   **getGaussian function is taken from
   https://en.wikipedia.org/wiki/Marsaglia_polar_method
   but is tweaked in order to work in C99 instead of Java
   PARALLEL version

*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <omp.h>






long double spare;
bool isSpareReady;

//calculates random numbers to be factored into by desired dart position (in location function)

long double getGaussian(long double mean, long double stdDev) {
  if (isSpareReady) {
    isSpareReady = false;
    return spare * stdDev + mean;
  } else {
    long double u, v, s;
    do {
      u = ((rand()/(long double)RAND_MAX) * 2) - 1;
      v = ((rand()/(long double)RAND_MAX) * 2) - 1;
      s = u * u + v * v;
        } while (s >= 1 || s == 0);
          long double mul = sqrt(-2.0 * log(s) / s);
          spare = v * mul;
          isSpareReady = true;
          return mean + stdDev * u * mul;
        }
}

//return the points of a dart thrown
long int points(long double angle, long double radius, long double r_angle, long double r_radius) {

  long double final_angle = r_angle + angle;
  long double final_radius = r_radius + radius;
  int score;
  //printf("final angle %Lf\n", final_angle);
  //printf("final radius %Lf\n", final_radius);

  //checking if radius is in bounds
  //while(final_radius != 0) {
  if(final_radius>20 || final_radius<=0) { //checking if radius is in bounds
    //printf("Dart did not score any points");
    goto END;
    return 0;
  }
    //checking if dart is thrown at 13 triangle
  if(final_angle >9  && final_angle <=27) {
    score = 13;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
     }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
        score = score;
    }
}

  //checking if dart is thrown at 4 triangle
  if(final_angle >27  && final_angle <=45) {
     score = 4;
     if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
       score = score * 2;
      }
     if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
       score = score * 3;
      }
     //checking to see if dart score is itself (no multiplier)
     if (final_radius >3 && final_radius <12){
       score = score;
     }
     if (final_radius >14 && final_radius <18) {
       score = score;
     }
}

  //checking if dart is thrown at 18 triangle
  if(final_angle >45 && final_angle <=63) {
     score = 18;
     if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
       score = score * 2;
      }
     if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
       score = score * 3;
      }
     //checking to see if dart score is itself (no multiplier)
     if (final_radius >3 && final_radius <12){
       score = score;
      }
     if (final_radius >14 && final_radius <18) {
       score = score;
      }
}

  //...at 1 triangle
  if(final_angle >63 && final_angle <=81) {
     score = 1;
     if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
       score = score * 2;
      }
     if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
       score = score * 3;
      }
    //checking to see if dart score is itself (no multiplier)
     if (final_radius >3 && final_radius <12){
       score = score;
      }
     if (final_radius >14 && final_radius <18) {
       score = score;
      }
}

  //...at 20 triangle
  if(final_angle >81 && final_angle <=99) {
     score = 20;
     if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
       score = score * 2;
      }
     if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
      }
     //checking to see if dart score is itself (no multiplier)
     if (final_radius >3 && final_radius <12){
       score = score;
      }
     if (final_radius >14 && final_radius <18) {
       score = score;
      }
  }

  //...at 5 triangle
  if(final_angle >99 && final_angle <=117) {
     score = 15;
     if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
       score = score * 2;
      }
     if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
       score = score * 3;
      }
     //checking to see if dart score is itself (no multiplier)
     if (final_radius >3 && final_radius <12){
       score = score;
      }
     if (final_radius >14 && final_radius <18) {
       score = score;
     }
}

  //...at 12 triangle
  if(final_angle >117 && final_angle <=135) {
     score = 12;
     if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
       score = score * 2;
      }
     if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
       score = score * 3;
      }
     //checking to see if dart score is itself (no multiplier)
     if (final_radius >3 && final_radius <12){
       score = score;
      }
     if (final_radius >14 && final_radius <18) {
       score = score;
      }
}

  //...at 9 triangle
  if(final_angle> 135 && final_angle <=153) {
     score = 9;
     if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
       score = score * 2;
      }
     if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
       score = score * 3;
      }
     //checking to see if dart score is itself (no multiplier)
     if (final_radius >3 && final_radius <12){
	     score = score;
      }
     if (final_radius >14 && final_radius <18) {
       score = score;
      }
  }

  //...at 14 triangle
  if(final_angle >153 && final_angle <=171) {
     score = 14;
     if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
       score = score * 2;
     }
     if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
       score = score * 3;
     }
     //checking to see if dart score is itself (no multiplier)
     if (final_radius >3 && final_radius <12){
       score = score;
     }
     if (final_radius >14 && final_radius <18) {
       score = score;
     }
}

  //...at 11 triangle
  if(final_angle >171 && final_angle <=189) {
    score = 11;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
    }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
    }
}


  //...at 8 triangle
  if(final_angle >189 && final_angle <=207) {
    score = 8;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
    }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
  }
}

  //...at 16 triangle
  if(final_angle >207 && final_angle <=225) {
    score = 16;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
     }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
     }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
    }
}

  //...at 7 triangle
  if(final_angle >225 && final_angle <=243) {
    score = 7;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
    }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
    }
}

  //...at 19 triangle
  if(final_angle >243 && final_angle <=261) {
    score = 19;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
    }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
    }
}

  //...at 3 triangle
  if(final_angle >261 && final_angle <=279) {
    score = 3;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
    }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
    }
}

  //...at 17 triangle
  if(final_angle >279 && final_angle <=297) {
    score = 17;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
    }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
    }
}

  //...at 2 triangle
  if(final_angle >297 && final_angle <=315) {
    score = 2;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
    }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
    }
}

  //...at 15 triangle
  if(final_angle >315 && final_angle <=333) {
    score = 15;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
    }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
    }
}

  //...at 10 triangle
  if(final_angle >333 && final_angle <351) {
    score = 10;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
    }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
    }
  }



  //...at 6 triangle
  if((final_angle > 351 && final_angle <=360) || (final_angle >=0 && final_angle <=9)) {
    score = 6;
    if (final_radius >=18 && final_radius <=20) { //checking to see if dart is in long double ring
      score = score * 2;
    }
    if (final_radius >=12 && final_radius <=14) { //checking to see if dart is in triple ring
      score = score * 3;
    }
    //checking to see if dart score is itself (no multiplier)
    if (final_radius >3 && final_radius <12){
      score = score;
    }
    if (final_radius >14 && final_radius <18) {
      score = score;
    }
  }

  //check if its at bullseye
  if(final_radius >0 && final_radius <1) {
    score = 50;
    }
  if (final_radius>=1 && final_radius<=3) {
    score = 25;
  }

   //printf("Your score is: ");
   return score;

   END:
    return 0; 

}




//takes in the users parameters and calculates random numbers using getGaussian function
//that are used as parameters for points function
void location(long double angle, long double radius, long double skill, int num, int threads) {
   srand(time(NULL));
   isSpareReady = false;
   long double r_angle[num];
   long double r_radius[num];
   long double temp = 0, average = 0;
   long double dart_num;

   int j;
   for (j=0; j<num; j++) { //loop in order to create the number of random numbers depending on user input
     r_angle[j] =  getGaussian(0, skill);
     r_radius[j] =  getGaussian(0, skill);
   }

   int i;
   long double final;

   #pragma omp parallel num_threads(threads)
    {
    printf("This is thread %d \n", omp_get_thread_num());
    #pragma omp for reduction(+:temp)
    for (i=0; i<num; i++) { //loop used to print points per each dart and to calculate the average of darts thrown
      final = points(angle, radius, r_angle[i], r_radius[i]);
      dart_num = i;
      //printf(" %Lf\n -- dart#%d \n",final, i);
      temp = temp + final;
    }
  }

      average =  temp/num;
      //printf("average = %Lf\n", average);
}




int main() {

  clock_t tic = clock();  //to compute execution time

  long double an,r;
  long double sl;
  int num;
  int nthreads;

  /*printf("enter in desired angle (0-359)\n");
  scanf("%Lf", &an);
  printf("enter in desired radius (0-20)\n");
  scanf("%Lf", &r);
  printf("enter in skill level (any number greater than 0)\n");
  scanf("%Lf", &sl);
  printf("enter in number of darts thrown \n");
  scanf("%ld", &num);
  location(an,r,sl,num);
  sl = sl*3;*/
  printf("Number of threads: \n");
  scanf("%d", &nthreads );
  printf("How many darts do you want to throw? \n");
  scanf("%d", &num);
  location(10,10,2,num, nthreads);

  clock_t toc = clock();

  printf("Elapsed: %Lf seconds\n", (long double)(toc-tic)/CLOCKS_PER_SEC); //prints out execution time

  return 0;

}
