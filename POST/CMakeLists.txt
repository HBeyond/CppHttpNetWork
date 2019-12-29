add_executable(Post_Download1 Post_Download1.cpp)
#target_include_directories(Post_Download1 PUBLIC
#        $<INSTALL_INTERFACE:include>
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#        ${PUBLIC_DEPEND_INCLUDES})
#target_include_directories(Post_Download1 PRIVATE
#        ${CMAKE_CURRENT_SOURCE_DIR}/src
#        ${PRIVATE_DEPEND_INCLUDES})
target_link_libraries(Post_Download1
        PUBLIC ${PUBLIC_DEPEND_LIBS}
        PRIVATE ${PRIVATE_DEPEND_LIBS} curl)

add_executable(Post_Upload1 Post_Upload1.cpp)
#target_include_directories(Post_Upload1 PUBLIC
#            $<INSTALL_INTERFACE:include>
#            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#            ${PUBLIC_DEPEND_INCLUDES})
#target_include_directories(Post_Upload1 PRIVATE
#            ${CMAKE_CURRENT_SOURCE_DIR}/src
#            ${PRIVATE_DEPEND_INCLUDES})
target_link_libraries(Post_Upload1
            PUBLIC ${PUBLIC_DEPEND_LIBS}
            PRIVATE ${PRIVATE_DEPEND_LIBS} curl)


add_executable(Post_getinmemory Post_getinmemory.cpp)
#target_include_directories(Post_getinmemory PUBLIC
#                $<INSTALL_INTERFACE:include>
#                $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#                ${PUBLIC_DEPEND_INCLUDES})
#target_include_directories(Post_getinmemory PRIVATE
#                ${CMAKE_CURRENT_SOURCE_DIR}/src
#                ${PRIVATE_DEPEND_INCLUDES})
target_link_libraries(Post_getinmemory
                PUBLIC ${PUBLIC_DEPEND_LIBS}
                PRIVATE ${PRIVATE_DEPEND_LIBS} curl)


add_executable(Post_Download2 Post_Download2.cpp)
target_link_libraries(Post_Download2
                            PUBLIC ${PUBLIC_DEPEND_LIBS}
                            PRIVATE ${PRIVATE_DEPEND_LIBS} curl)

add_executable(Post_Download3 Post_Download3.cpp)
target_link_libraries(Post_Download3 PUBLIC ${PUBLIC_DEPEND_LIBS} PRIVATE ${PRIVATE_DEPEND_LIBS} curl)

add_executable(Post_Download4 Post_Download4.cpp)
target_link_libraries(Post_Download4 PUBLIC ${PUBLIC_DEPEND_LIBS} PRIVATE ${PRIVATE_DEPEND_LIBS} curl)
