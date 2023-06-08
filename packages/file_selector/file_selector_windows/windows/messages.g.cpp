// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
// Autogenerated from Pigeon (v9.1.1), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#undef _HAS_EXCEPTIONS

#include "messages.g.h"

#include <flutter/basic_message_channel.h>
#include <flutter/binary_messenger.h>
#include <flutter/encodable_value.h>
#include <flutter/standard_message_codec.h>

#include <map>
#include <optional>
#include <string>

namespace file_selector_windows {
using flutter::BasicMessageChannel;
using flutter::CustomEncodableValue;
using flutter::EncodableList;
using flutter::EncodableMap;
using flutter::EncodableValue;

// TypeGroup

const std::string& TypeGroup::label() const { return label_; }
void TypeGroup::set_label(std::string_view value_arg) { label_ = value_arg; }

const EncodableList& TypeGroup::extensions() const { return extensions_; }
void TypeGroup::set_extensions(const EncodableList& value_arg) {
  extensions_ = value_arg;
}

EncodableList TypeGroup::ToEncodableList() const {
  EncodableList list;
  list.reserve(2);
  list.push_back(EncodableValue(label_));
  list.push_back(EncodableValue(extensions_));
  return list;
}

TypeGroup::TypeGroup() {}

TypeGroup::TypeGroup(const EncodableList& list) {
  auto& encodable_label = list[0];
  if (const std::string* pointer_label =
          std::get_if<std::string>(&encodable_label)) {
    label_ = *pointer_label;
  }
  auto& encodable_extensions = list[1];
  if (const EncodableList* pointer_extensions =
          std::get_if<EncodableList>(&encodable_extensions)) {
    extensions_ = *pointer_extensions;
  }
}

// SelectionOptions

bool SelectionOptions::allow_multiple() const { return allow_multiple_; }
void SelectionOptions::set_allow_multiple(bool value_arg) {
  allow_multiple_ = value_arg;
}

bool SelectionOptions::select_folders() const { return select_folders_; }
void SelectionOptions::set_select_folders(bool value_arg) {
  select_folders_ = value_arg;
}

const EncodableList& SelectionOptions::allowed_types() const {
  return allowed_types_;
}
void SelectionOptions::set_allowed_types(const EncodableList& value_arg) {
  allowed_types_ = value_arg;
}

EncodableList SelectionOptions::ToEncodableList() const {
  EncodableList list;
  list.reserve(3);
  list.push_back(EncodableValue(allow_multiple_));
  list.push_back(EncodableValue(select_folders_));
  list.push_back(EncodableValue(allowed_types_));
  return list;
}

SelectionOptions::SelectionOptions() {}

SelectionOptions::SelectionOptions(const EncodableList& list) {
  auto& encodable_allow_multiple = list[0];
  if (const bool* pointer_allow_multiple =
          std::get_if<bool>(&encodable_allow_multiple)) {
    allow_multiple_ = *pointer_allow_multiple;
  }
  auto& encodable_select_folders = list[1];
  if (const bool* pointer_select_folders =
          std::get_if<bool>(&encodable_select_folders)) {
    select_folders_ = *pointer_select_folders;
  }
  auto& encodable_allowed_types = list[2];
  if (const EncodableList* pointer_allowed_types =
          std::get_if<EncodableList>(&encodable_allowed_types)) {
    allowed_types_ = *pointer_allowed_types;
  }
}

FileSelectorApiCodecSerializer::FileSelectorApiCodecSerializer() {}
EncodableValue FileSelectorApiCodecSerializer::ReadValueOfType(
    uint8_t type, flutter::ByteStreamReader* stream) const {
  switch (type) {
    case 128:
      return CustomEncodableValue(
          SelectionOptions(std::get<EncodableList>(ReadValue(stream))));
    case 129:
      return CustomEncodableValue(
          TypeGroup(std::get<EncodableList>(ReadValue(stream))));
    default:
      return flutter::StandardCodecSerializer::ReadValueOfType(type, stream);
  }
}

void FileSelectorApiCodecSerializer::WriteValue(
    const EncodableValue& value, flutter::ByteStreamWriter* stream) const {
  if (const CustomEncodableValue* custom_value =
          std::get_if<CustomEncodableValue>(&value)) {
    if (custom_value->type() == typeid(SelectionOptions)) {
      stream->WriteByte(128);
      WriteValue(
          EncodableValue(
              std::any_cast<SelectionOptions>(*custom_value).ToEncodableList()),
          stream);
      return;
    }
    if (custom_value->type() == typeid(TypeGroup)) {
      stream->WriteByte(129);
      WriteValue(EncodableValue(
                     std::any_cast<TypeGroup>(*custom_value).ToEncodableList()),
                 stream);
      return;
    }
  }
  flutter::StandardCodecSerializer::WriteValue(value, stream);
}

/// The codec used by FileSelectorApi.
const flutter::StandardMessageCodec& FileSelectorApi::GetCodec() {
  return flutter::StandardMessageCodec::GetInstance(
      &FileSelectorApiCodecSerializer::GetInstance());
}

// Sets up an instance of `FileSelectorApi` to handle messages through the
// `binary_messenger`.
void FileSelectorApi::SetUp(flutter::BinaryMessenger* binary_messenger,
                            FileSelectorApi* api) {
  {
    auto channel = std::make_unique<BasicMessageChannel<>>(
        binary_messenger, "dev.flutter.pigeon.FileSelectorApi.showOpenDialog",
        &GetCodec());
    if (api != nullptr) {
      channel->SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_options_arg = args.at(0);
              if (encodable_options_arg.IsNull()) {
                reply(WrapError("options_arg unexpectedly null."));
                return;
              }
              const auto& options_arg = std::any_cast<const SelectionOptions&>(
                  std::get<CustomEncodableValue>(encodable_options_arg));
              const auto& encodable_initial_directory_arg = args.at(1);
              const auto* initial_directory_arg =
                  std::get_if<std::string>(&encodable_initial_directory_arg);
              const auto& encodable_confirm_button_text_arg = args.at(2);
              const auto* confirm_button_text_arg =
                  std::get_if<std::string>(&encodable_confirm_button_text_arg);
              ErrorOr<EncodableList> output = api->ShowOpenDialog(
                  options_arg, initial_directory_arg, confirm_button_text_arg);
              if (output.has_error()) {
                reply(WrapError(output.error()));
                return;
              }
              EncodableList wrapped;
              wrapped.push_back(EncodableValue(std::move(output).TakeValue()));
              reply(EncodableValue(std::move(wrapped)));
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel->SetMessageHandler(nullptr);
    }
  }
  {
    auto channel = std::make_unique<BasicMessageChannel<>>(
        binary_messenger, "dev.flutter.pigeon.FileSelectorApi.showSaveDialog",
        &GetCodec());
    if (api != nullptr) {
      channel->SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_options_arg = args.at(0);
              if (encodable_options_arg.IsNull()) {
                reply(WrapError("options_arg unexpectedly null."));
                return;
              }
              const auto& options_arg = std::any_cast<const SelectionOptions&>(
                  std::get<CustomEncodableValue>(encodable_options_arg));
              const auto& encodable_initial_directory_arg = args.at(1);
              const auto* initial_directory_arg =
                  std::get_if<std::string>(&encodable_initial_directory_arg);
              const auto& encodable_suggested_name_arg = args.at(2);
              const auto* suggested_name_arg =
                  std::get_if<std::string>(&encodable_suggested_name_arg);
              const auto& encodable_confirm_button_text_arg = args.at(3);
              const auto* confirm_button_text_arg =
                  std::get_if<std::string>(&encodable_confirm_button_text_arg);
              ErrorOr<EncodableList> output = api->ShowSaveDialog(
                  options_arg, initial_directory_arg, suggested_name_arg,
                  confirm_button_text_arg);
              if (output.has_error()) {
                reply(WrapError(output.error()));
                return;
              }
              EncodableList wrapped;
              wrapped.push_back(EncodableValue(std::move(output).TakeValue()));
              reply(EncodableValue(std::move(wrapped)));
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel->SetMessageHandler(nullptr);
    }
  }
}

EncodableValue FileSelectorApi::WrapError(std::string_view error_message) {
  return EncodableValue(
      EncodableList{EncodableValue(std::string(error_message)),
                    EncodableValue("Error"), EncodableValue()});
}
EncodableValue FileSelectorApi::WrapError(const FlutterError& error) {
  return EncodableValue(EncodableList{EncodableValue(error.code()),
                                      EncodableValue(error.message()),
                                      error.details()});
}

}  // namespace file_selector_windows
