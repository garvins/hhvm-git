/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "clone.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_clone,
	const String& url,
	const String& local_path,
	const Resource& options)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_repository *out = NULL;

	auto options_ = dyn_cast<Git2Resource>(options);

	result = git_clone(&out, url.c_str(), local_path.c_str(), HHVM_GIT2_V(options_, clone_options));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, repository) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_clone_into,
	const Resource& repo,
	const Resource& remote,
	const Resource& co_opts,
	const String& branch)
{
	int result;
	int64_t return_value;

	auto repo_ = dyn_cast<Git2Resource>(repo);
	auto remote_ = dyn_cast<Git2Resource>(remote);
	auto co_opts_ = dyn_cast<Git2Resource>(co_opts);

	result = git_clone_into(HHVM_GIT2_V(repo_, repository), HHVM_GIT2_V(remote_, remote), HHVM_GIT2_V(co_opts_, checkout_opts), branch.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

