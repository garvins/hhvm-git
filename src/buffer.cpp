/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "buffer.h"

using namespace HPHP;

void HHVM_FUNCTION(git_buf_free,
	const Resource& buffer)
{

	auto buffer_ = dyn_cast<Git2Resource>(buffer);

	git_buf_free(HHVM_GIT2_V(buffer_, buf));
}

int64_t HHVM_FUNCTION(git_buf_grow,
	const Resource& buffer,
	int64_t target_size)
{
	int result;
	int64_t return_value;

	auto buffer_ = dyn_cast<Git2Resource>(buffer);

	result = git_buf_grow(HHVM_GIT2_V(buffer_, buf), (size_t) target_size);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

int64_t HHVM_FUNCTION(git_buf_set,
	const Resource& buffer,
	const Variant& data,
	int64_t datalen)
{
	int result;
	int64_t return_value;

	void *data_ = NULL;

	auto buffer_ = dyn_cast<Git2Resource>(buffer);

	result = git_buf_set(HHVM_GIT2_V(buffer_, buf), data_, (size_t) datalen);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

