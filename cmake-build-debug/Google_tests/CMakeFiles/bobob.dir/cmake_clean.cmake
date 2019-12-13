file(REMOVE_RECURSE
  "bobob"
  "bobob.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/bobob.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
