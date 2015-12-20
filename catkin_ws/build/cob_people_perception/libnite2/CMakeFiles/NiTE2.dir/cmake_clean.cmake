FILE(REMOVE_RECURSE
  "/home/human/catkin_ws/devel/lib/libNiTE2.pdb"
  "/home/human/catkin_ws/devel/lib/libNiTE2.so"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/NiTE2.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
