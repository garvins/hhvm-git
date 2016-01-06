/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#include "hphp/runtime/ext/extension.h"
#include "hphp/system/systemlib.h"

#include "../ext_git2.h"
#include "odb_backend.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_odb_backend_pack,
	const String& objects_dir)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb_backend **out = NULL;

	git_odb_backend_pack(out, objects_dir.c_str());
	HHVM_GIT2_V(return_value, odb_backend) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_odb_backend_loose,
	const String& objects_dir,
	int64_t compression_level,
	int64_t do_fsync,
	int64_t dir_mode,
	int64_t file_mode)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb_backend **out = NULL;

	git_odb_backend_loose(out, objects_dir.c_str(), (int) compression_level, (int) do_fsync, (unsigned int) dir_mode, (unsigned int) file_mode);
	HHVM_GIT2_V(return_value, odb_backend) = *out;
	return Resource(return_value);
}

Resource HHVM_FUNCTION(git_odb_backend_one_pack,
	const String& index_file)
{
	Git2Resource *return_value = new Git2Resource();

	git_odb_backend **out = NULL;

	git_odb_backend_one_pack(out, index_file.c_str());
	HHVM_GIT2_V(return_value, odb_backend) = *out;
	return Resource(return_value);
}

