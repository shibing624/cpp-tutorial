//
// Created by Xu,Ming(RCPT) on 17/8/16.
//

#ifndef CPP_TUTORIAL_CONFIG_H_H
#define CPP_TUTORIAL_CONFIG_H_H

#include <string>
#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>

namespace familia {
    void protobuf_AddDesc_config_2eproto();

    void protobuf_AssignDesc_config_2eproto();

    void protobuf_ShutdownFile_config_2eproto();

    class ModelConfig;

    enum ModelType {
        LDA = 0,
        SLDA = 1
    };

    bool ModelType_IsValid(int value);

    const ModelType ModelType_MIN = LDA;
    const ModelType ModelType_MAX = SLDA;
    const int ModelType_ARRAYSIZE = ModelType_MAX + 1;

    const ::google::protobuf::EnumDescriptor *ModelType_descriptor();

    inline const ::std::string &ModelType_Name(ModelType value) {
        return ::google::protobuf::internal::NameOfEnum(
                ModelType_descriptor(), value);
    }

    inline bool ModelType_Parse(const ::std::string &name, ModelType *value) {
        return google::protobuf::internal::ParseNamedEnum<ModelType>(ModelType_descriptor(), name, value);
    }

    class ModelConfig : public google::protobuf::Message {
    public:
        ModelConfig();

        virtual ~ModelConfig();

        ModelConfig(const ModelConfig &from);

        inline ModelConfig &operator=(const ModelConfig &from) {
            CopyFrom(from);
            return *this;
        }

        inline const google::protobuf::UnknownFieldSet& unknown_fields() const{
            return _unknown_fields_;
        }

        inline google::protobuf::UnknownFieldSet* mutable_unknown_fields(){
            return &_unknown_fields_;
        }

        static const google::protobuf::Descriptor* descriptor();
        static const ModelConfig& default_instance();
        void Swap(ModelConfig* other);

        ModelConfig* New() const;
        void CopyFrom(const google::protobuf::Message& from);
        void MergeFrom(const google::protobuf::Message& from);
        void CopyFrom(const ModelConfig& from);
        void MergeFrom(const ModelConfig& from);
        void Clear();
        bool IsInitialized() const;
        int ByteSize() const;
        bool MergePartialFromCodedStream(google::protobuf::io::CodedInputStream* input);
        void SerializeWithCachedSizes(google::protobuf::io::CodedOutputStream* output) const;
        google::protobuf::unit8* SerializeWithCachedSizesToArray(google::protobuf::uint8* output) const;
        int GetCachedSize() const{
            return _cached_size_;
        }

    private:
        void SharedCtor();
        void SharedDtor();
        void SetCachedSize(int size) const;


    };

}

#endif //CPP_TUTORIAL_CONFIG_H_H
