// Copyright (c) 2012-2018, The CryptoNote developers, The qCoin developers.
// Licensed under the GNU Lesser General Public License. See LICENSE for details.

#pragma once

#include <memory>
#include <vector>
//#include <mutex>
#include "LoggerGroup.hpp"
#include "LoggerMessage.hpp"

namespace logging {

class LoggerManager : public LoggerGroup {
public:
	LoggerManager() = default;
	void configure_default(const std::string &log_folder, const std::string &log_prefix, const std::string &version);
	// log_folder must exist
	virtual void write(
	    const std::string &category, Level level, boost::posix_time::ptime time, const std::string &body) override;

private:
	std::vector<std::unique_ptr<CommonLogger>> loggers;
};
}  // namespace logging
