/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "refdb.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_refdb_new,
	const Resource& repo)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_refdb *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_refdb_new(&out, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, refdb) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_refdb_open,
	const Resource& repo)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_refdb *out = NULL;

	auto repo_ = dyn_cast<Git2Resource>(repo);

	result = git_refdb_open(&out, HHVM_GIT2_V(repo_, repository));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, refdb) = out;
	return Resource(return_value);
}

int64_t HHVM_FUNCTION(git_refdb_compress,
	const Resource& refdb)
{
	int result;
	int64_t return_value;

	auto refdb_ = dyn_cast<Git2Resource>(refdb);

	result = git_refdb_compress(HHVM_GIT2_V(refdb_, refdb));

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	return_value = (int64_t) result;
	return return_value;
}

void HHVM_FUNCTION(git_refdb_free,
	const Resource& refdb)
{

	auto refdb_ = dyn_cast<Git2Resource>(refdb);

	git_refdb_free(HHVM_GIT2_V(refdb_, refdb));
}

