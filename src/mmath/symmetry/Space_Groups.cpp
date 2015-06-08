#include "Space_Groups.h"

using namespace std;

namespace libmmath{

using namespace liblinalg;

namespace libsymmetry{



int is_int_transl(double rem,double eps){

   int res;
   double frem = std::fabs(rem);
  
   if((frem<eps)||(std::fabs(1.0-frem)<eps)){ res = 1; }
   else{ res = 0;}

   return res;
}

void Apply_Symmetry(std::string space_group_name,VECTOR r,std::vector<VECTOR>& r_equiv){
// This function applies the symmetry defined by a space group Space_Group to
// the vector r. New symmetrically equivalent positions (as well as original point r)
// then added to array r_equiv. If new position just created by one of the group
// operations is already included in r_equive then we do not include it again.
// Also we do not include points which are just translations of the original point r
// on any integer (also 0) number of lattice cell dimentions.

   double remx,remy,remz;
   double eps = 1e-5;

   SPACE_GROUP sg(space_group_name);
   MATRIX mr(4,1); 
          mr.M[0] = r.x;
          mr.M[1] = r.y;
          mr.M[2] = r.z;
          mr.M[3] = 1.0;
   MATRIX R;
   VECTOR vR;

   // Add original point to list of equivalent positions
   r_equiv.push_back(r);

   for(int i=0;i<sg.operators.size();i++){

       R = sg.operators[i]*mr;
       vR.x = R.M[0];
       vR.y = R.M[1];
       vR.z = R.M[2];

       /* Now check if this vector can be obtained from one of
          the already included positions by integer translations
        */

       int is_new = 1;
       for(int j=0;j<r_equiv.size();j++){
           remx = std::fmod((vR.x - r_equiv[j].x),1.0);
           remy = std::fmod((vR.y - r_equiv[j].y),1.0);
           remz = std::fmod((vR.z - r_equiv[j].z),1.0);
          
           int is_remx = is_int_transl(remx,eps);
           int is_remy = is_int_transl(remy,eps);
           int is_remz = is_int_transl(remz,eps);
           int is_transl = is_remx * is_remy * is_remz;
           if(is_transl){
           // vR is an integer translation of r_equiv[j]
              is_new = 0; break;
           }

       }// for j

       // Debug
       //std::cout<<i<<"  "<<r<<"  "<<vR<<" "<<is_new<<std::endl;

       // Add this point since it is not included
       if(is_new){
          r_equiv.push_back(vR);
       }

   }// for i

}// Apply_Symmetry

}//namespace libsymmetry
}//namespace libmmath

