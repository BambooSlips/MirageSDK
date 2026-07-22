###################################################################################################
cmake_minimum_required(VERSION 3.21)

project(Mirage)
set(CMAKE_CXX_STANDARD 20)
set(SAMPLE_OUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/out/)
set(SAMPLE_DATA_PATH ${MIRAGE_SDK_PATH}/data/)
message(STATUS "[example] CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "[example] SAMPLE_OUT_PATH: ${SAMPLE_OUT_PATH}")
message(STATUS "[example] SAMPLE_DATA_PATH: ${SAMPLE_DATA_PATH}")
###################################################################################################
# dependency control 
if(TARGET mirage)
   message(STATUS "Target mirage is already defined.")
else()
   if(WIN32)
      set(MIRAGE_LIB_PATH ${MIRAGE_SDK_PATH}/lib/win_x86_64/libmirage.dll)
   else()
      set(MIRAGE_LIB_PATH ${MIRAGE_SDK_PATH}/lib/linux_x86_64/libmirage.so)
   endif()

   add_library(mirage SHARED IMPORTED)

   set_target_properties(mirage PROPERTIES 
      IMPORTED_LOCATION ${MIRAGE_LIB_PATH}
      INTERFACE_INCLUDE_DIRECTORIES ${MIRAGE_SDK_PATH}/inc
   )
endif()
###################################################################################################
# build SampleApp
set(SOURCE_FILE SampleApp.cpp
                SampleLayer.cpp
                DemoOverlay.cpp
)

set(HEADER_FILE ${MIRAGE_SDK_PATH}/inc/common_def.hpp
                ${MIRAGE_SDK_PATH}/inc/base_layer.hpp
                ${MIRAGE_SDK_PATH}/inc/base_event.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageObject.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageComponent.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageTransform.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageApplication.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageLog.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageMeshFilter.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageMaterial.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageMeshRenderer.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageCamera.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageFont.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageInput.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageImage.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageText.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageButton.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageObserver.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageAudioSource.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageAudioBuffer.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageAudioListener.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageAudioUtils.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageAnimation.hpp
                ${MIRAGE_SDK_PATH}/inc/MirageVertexBoneInfo.hpp
                SampleLayer.hpp
                DemoOverlay.hpp
)

add_executable(SampleApp ${SOURCE_FILE} ${HEADER_FILE})                  
target_include_directories(SampleApp PRIVATE ${MIRAGE_SDK_PATH}/inc)
target_link_libraries(SampleApp PRIVATE mirage)

target_compile_definitions(SampleApp PUBLIC
   APP_WORKSPACE="${SAMPLE_DATA_PATH}"
)

set_target_properties(SampleApp PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY ${SAMPLE_OUT_PATH}
)
###################################################################################################
# Copy shared libs after building
add_custom_command(TARGET SampleApp POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy
   ${MIRAGE_LIB_PATH}
   ${SAMPLE_OUT_PATH}
)
###################################################################################################