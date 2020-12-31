file(REMOVE_RECURSE
  "A.exe"
  "A.exe.manifest"
  "A.pdb"
  "CMakeFiles/A.dir/A.cpp.obj"
  "libA.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/A.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
