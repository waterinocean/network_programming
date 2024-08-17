
set(client_src  ${CMAKE_CURRENT_SOURCE_DIR}/client.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/lfileclient.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/ltcpclient.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/lmsgparser.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/lmsgbuilder.cpp
)
add_executable(client ${client_src})
target_include_directories(client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(server_src  ${CMAKE_CURRENT_SOURCE_DIR}/server.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/lfileserver.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/ltcpserver.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/lmsgparser.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/lmsgbuilder.cpp
)
add_executable(server ${server_src})
target_include_directories(server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
