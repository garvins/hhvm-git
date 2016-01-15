/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "odb_backend.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_odb_backend_pack,
	const String& objects_dir)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_odb_backend *out = NULL;

	result = git_odb_backend_pack(&out, objects_dir.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, odb_backend) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_odb_backend_loose,
	const String& objects_dir,
	int64_t compression_level,
	int64_t do_fsync,
	int64_t dir_mode,
	int64_t file_mode)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_odb_backend *out = NULL;

	result = git_odb_backend_loose(&out, objects_dir.c_str(), (int) compression_level, (int) do_fsync, (unsigned int) dir_mode, (unsigned int) file_mode);

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, odb_backend) = out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_odb_backend_one_pack,
	const String& index_file)
{
	int result;
	auto return_value = req::make<Git2Resource>();

	git_odb_backend *out = NULL;

	result = git_odb_backend_one_pack(&out, index_file.c_str());

	if (result != GIT_OK) {
		const git_error *error = giterr_last();
		SystemLib::throwInvalidArgumentExceptionObject(error ? error->message : "no error message");
	}

	HHVM_GIT2_V(return_value, odb_backend) = out;
	return Resource(return_value);
}

