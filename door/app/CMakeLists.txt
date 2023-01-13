set(_target "app")

set(_source_files   "diag_swc.c")

set(_include_dir      
   )

# Public headers 
set (_public_headers ".")

set (_depend_libs)

add_library(${_target}
  ${_source_files}
)

target_link_libraries(${_target}
  ${_depend_libs}
)

target_include_directories( ${_target} 
	PRIVATE ${_include_dir}
	PUBLIC  ${_public_headers})

# copy the binary files in the install directory
install(
  TARGETS     ${_target}
  DESTINATION bin
)