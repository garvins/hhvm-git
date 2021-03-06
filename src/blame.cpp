/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "blame.h"

using namespace HPHP;

int64_t HHVM_FUNCTION(git_blame_get_hunk_count,
	const Resource& blame)
{
	uint32_t result;
	int64_t return_value;

	auto blame_ = dyn_cast<Git2Resource>(blame);

	result = git_blame_get_hunk_count(HHVM_GIT2_V(blame_, blame));
	return_value = (int64_t) result;
	return return_value;
}

Resource HHVM_FUNCTION(git_blame_get_hunk_byindex,
	const Resource& blame,
	int64_t index)
{
	const git_blame_hunk *result;
	auto return_value = req::make<Git2Resource>();

	auto blame_ = dyn_cast<Git2Resource>(blame);

	result = git_blame_get_hunk_byindex(HHVM_GIT2_V(blame_, blame), (uint32_t) index);
	//HHVM_GIT2_V(return_value, blame_hunk) = result; todo return as array
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_blame_get_hunk_byline,
	const Resource& blame,
	int64_t lineno)
{
	const git_blame_hunk *result;
	auto return_value = req::make<Git2Resource>();

	auto blame_ = dyn_cast<Git2Resource>(blame);

	result = git_blame_get_hunk_byline(HHVM_GIT2_V(blame_, blame), (uint32_t) lineno);
	//HHVM_GIT2_V(return_value, blame_hunk) = result; todo return as array
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_blame_file,
	const Resource& repo,
	const String& path,
	const Array& options)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_blame *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_blame_file(&out, HHVM_GIT2_V(repo_, repository), path.c_str(), NULL);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, blame) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_blame_buffer,
	const Resource& reference,
	const String& buffer,
	int64_t buffer_len)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_blame *out = NULL;

	auto reference_ = dyn_cast<Git2Resource>(reference);

	result = git_blame_buffer(&out, HHVM_GIT2_V(reference_, blame), buffer.c_str(), (uint32_t) buffer_len);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, blame) = out;
	return Resource(return_value);
}

void HHVM_FUNCTION(git_blame_free,
	const Resource& blame)
{

	auto blame_ = dyn_cast<Git2Resource>(blame);

	git_blame_free(HHVM_GIT2_V(blame_, blame));
}

