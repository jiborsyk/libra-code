#*********************************************************************************
#* Copyright (C) 2015-2016 Alexey V. Akimov
#*
#* This file is distributed under the terms of the GNU General Public License
#* as published by the Free Software Foundation, either version 2 of
#* the License, or (at your option) any later version.
#* See the file LICENSE in the root directory of this distribution
#* or <http://www.gnu.org/licenses/>.
#*
#*********************************************************************************/

###################################################################
# Tutorial: Loading structure from files
###################################################################

import os
import sys
import math

# Fisrt, we add the location of the library to test to the PYTHON path
if sys.platform=="cygwin":
    from cyglibra_core import *
elif sys.platform=="linux" or sys.platform=="linux2":
    from liblibra_core import *
from libra_py import *



##############################################################

# Create Universe and populate it
U = Universe()
verbose = 0
LoadPT.Load_PT(U, "elements.dat", verbose)


# Now to Systems
i = 1
while i<=19:
    print "=====================System", i,"====================="
    # System creation section
    syst = System()

    # Create atoms, link them, define groups
    inp_file = os.getcwd()+"/Molecules/test"+str(i)+"a.pdb"
    LoadMolecule.Load_Molecule(U, syst, inp_file, "pdb_1")

    syst.determine_functional_groups(1)  # 1 - determine rings
    syst.show_atoms()
    print "======================================================="

    i = i + 1



