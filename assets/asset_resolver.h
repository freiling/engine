// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_ASSETS_ASSET_RESOLVER_H_
#define FLUTTER_ASSETS_ASSET_RESOLVER_H_

#include <string>
#include <vector>

#include "flutter/fml/macros.h"
#include "flutter/fml/mapping.h"

namespace flutter {

class AssetResolver {
 public:
  AssetResolver() = default;

  virtual ~AssetResolver() = default;

  virtual bool IsValid() const = 0;

  [[nodiscard]] virtual std::unique_ptr<fml::Mapping> GetAsMapping(
      const std::string& asset_name) const = 0;

  // Same as GetAsMapping() but returns mappings for all files who's name
  // matches |pattern|. Returns empty vector if no matching assets are found
  [[nodiscard]] virtual std::vector<std::unique_ptr<fml::Mapping>>
  GetAsMappings(const std::string& asset_pattern) const = 0;

 private:
  FML_DISALLOW_COPY_AND_ASSIGN(AssetResolver);
};

}  // namespace flutter

#endif  // FLUTTER_ASSETS_ASSET_RESOLVER_H_
