set(_target "light.bin")

set(_source_files   "main_swc.c")


set(_include_dir      )

# Public headers 
set (_public_headers )


set (_depend_libs   "pthread"
                    "rte")

add_executable(${_target}
  ${_source_files}
)

target_link_libraries(${_target}
  ${_depend_libs}
)

#Public headers for the project
target_include_directories( ${_target} 
  PRIVATE ${_include_dir}
  PUBLIC  ${_public_headers})

# copy the binary files in the install directory
install(
  TARGETS     ${_target}
  DESTINATION bin
)