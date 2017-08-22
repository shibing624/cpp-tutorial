cmake_minimum_required(VERSION 3.8)
project(cpp-tutorial)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES
        familia/document.cpp
        familia/document.h
        familia/util.h
        familia/util.cpp
        familia/config.pb.cpp
        familia/config.pb.h
        familia/tokenizer.cpp
        familia/tokenizer.h
        demo/doc_distance_demo.cpp
        demo/show_topic_demo.cpp familia/vocab.cpp familia/vocab.h familia/sentence_document.cpp familia/sentence_document.h familia/vose_alias.cpp familia/vose_alias.h familia/model.cpp familia/model.h)
add_executable(cpp-tutorial ${SOURCE_FILES}
        demo/show_topic_demo.cpp
        demo/doc_distance_demo.cpp)