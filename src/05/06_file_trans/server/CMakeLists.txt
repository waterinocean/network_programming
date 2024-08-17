# set(server_src  ./server.cpp
#                 ./lfileserver.cpp
#                 ./ltcpserver.cpp
#                 ../public/lmsgparser.cpp
#                 ../public/lmsgbuilder.cpp
# )

set(server_src  ./server.cpp
)
add_executable(server ${server_src})
target_include_directories(server PRIVATE ./../../../../include/05/06_file_trans)
