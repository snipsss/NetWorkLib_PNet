cmake_minimum_required(VERSION 3.1)
project(PNetLib_Client_Server VERSION 1.0) 
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(Server Server/Source.cpp
                PNet/includeME.h
                PNet/IpEndPointr.h      PNet/IpEndPointr.cpp
                PNet/IpVersion.h        
                PNet/MyClassSocket.h    PNet/MyClassSocket.cpp
                PNet/NetWork.h          PNet/NetWork.cpp
                PNet/Package.h          PNet/Package.cpp
                PNet/PacketExc.h
                PNet/PacketType.h
                PNet/Presult.h
                PNet/SocketHandle.h      
                PNet/ValidatorIP.h      PNet/ValidatorIP.cpp
                PNet/Сonstant.h)
add_executable(Client Client/SourceClient.cpp
                PNet/includeME.h
                PNet/IpEndPointr.h      PNet/IpEndPointr.cpp
                PNet/IpVersion.h        
                PNet/MyClassSocket.h    PNet/MyClassSocket.cpp
                PNet/NetWork.h          PNet/NetWork.cpp
                PNet/Package.h          PNet/Package.cpp
                PNet/PacketExc.h
                PNet/PacketType.h
                PNet/Presult.h
                PNet/SocketHandle.h      
                PNet/ValidatorIP.h      PNet/ValidatorIP.cpp
                PNet/Сonstant.h
                )

set_target_properties(Server PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set_target_properties(Client PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
