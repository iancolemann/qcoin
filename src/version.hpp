// Copyright (c) 2012-2018, The CryptoNote developers, The qCoin developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

#pragma once

// defines are for Windows resource compiler
#define qcoin_VERSION_WINDOWS_COMMA 3, 19, 4, 18
#define qcoin_VERSION_STRING "v3.4.2 (amethyst)"

#ifndef RC_INVOKED  // Windows resource compiler

namespace cn {
inline const char *app_version() { return qcoin_VERSION_STRING; }
}  // namespace cn

#endif
