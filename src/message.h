/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_MESSAGE_H
#define HHVM_GIT2_MESSAGE_H


using namespace HPHP;

String HHVM_FUNCTION(git_message_prettify,
	int64_t out_size,
	const String& message,
	int64_t strip_comments);

#endif

