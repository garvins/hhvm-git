/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "sys_refdb_backend.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_refdb_backend_fs,
	const Resource& repo)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_refdb_backend *backend_out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_refdb_backend_fs(&backend_out, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, refdb_backend) = backend_out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_refdb_set_backend,
	const Resource& refdb,
	const Resource& backend)
{
	int result;
	int64_t return_value;

	auto refdb_ = dyn_cast<Git2Resource>(refdb);
	auto backend_ = dyn_cast<Git2Resource>(backend);

	result = git_refdb_set_backend(HHVM_GIT2_V(refdb_, refdb), HHVM_GIT2_V(backend_, refdb_backend));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

