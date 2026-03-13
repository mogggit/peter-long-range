# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/Morris/ECE342_Labs/perter-long-range/MDK-ARM/tmp/lab_05+lab_05")
  file(MAKE_DIRECTORY "C:/Users/Morris/ECE342_Labs/perter-long-range/MDK-ARM/tmp/lab_05+lab_05")
endif()
file(MAKE_DIRECTORY
  "C:/Users/Morris/ECE342_Labs/perter-long-range/MDK-ARM/tmp/1"
  "C:/Users/Morris/ECE342_Labs/perter-long-range/MDK-ARM/tmp/lab_05+lab_05"
  "C:/Users/Morris/ECE342_Labs/perter-long-range/MDK-ARM/tmp/lab_05+lab_05/tmp"
  "C:/Users/Morris/ECE342_Labs/perter-long-range/MDK-ARM/tmp/lab_05+lab_05/src/lab_05+lab_05-stamp"
  "C:/Users/Morris/ECE342_Labs/perter-long-range/MDK-ARM/tmp/lab_05+lab_05/src"
  "C:/Users/Morris/ECE342_Labs/perter-long-range/MDK-ARM/tmp/lab_05+lab_05/src/lab_05+lab_05-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Morris/ECE342_Labs/perter-long-range/MDK-ARM/tmp/lab_05+lab_05/src/lab_05+lab_05-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Morris/ECE342_Labs/perter-long-range/MDK-ARM/tmp/lab_05+lab_05/src/lab_05+lab_05-stamp${cfgdir}") # cfgdir has leading slash
endif()
