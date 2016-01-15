/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "message.h"

using namespace HPHP;

String HHVM_FUNCTION(git_message_prettify,
	int64_t out_size,
	const String& message,
	int64_t strip_comments)
{
	int result;
	String return_value;

	char out;

	result = git_message_prettify(&out, (size_t) out_size, message.c_str(), (int) strip_comments);

    if (result < 0) {
        const git_error *error = giterr_last();
        SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = String(&out);
	return return_value;
}

