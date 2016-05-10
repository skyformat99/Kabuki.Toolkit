#ifndef _PREAD_H
#define _PREAD_H

#include "mpi.h"
#include <vector>
#include <string>

namespace io
{
namespace hdf5
{

size_t read_particles(MPI_Comm comm,
                      const char *infile, int rank, int size,
                      std::vector <float> &particles,
                      const std::vector<std::string>& coordinates);

}
}

#endif
