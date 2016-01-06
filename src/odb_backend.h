/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_ODB_BACKEND_H
#define HHVM_GIT2_ODB_BACKEND_H


using namespace HPHP;

Resource HHVM_FUNCTION(git_odb_backend_pack,
	const String& objects_dir);

Resource HHVM_FUNCTION(git_odb_backend_loose,
	const String& objects_dir,
	int64_t compression_level,
	int64_t do_fsync,
	int64_t dir_mode,
	int64_t file_mode);

Resource HHVM_FUNCTION(git_odb_backend_one_pack,
	const String& index_file);

#endif

