/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_REFLOG_H
#define HHVM_GIT2_REFLOG_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_reflog_read,
	const Resource& repo,
	const String& name);

int64_t HHVM_FUNCTION(git_reflog_write,
	const Resource& reflog);

int64_t HHVM_FUNCTION(git_reflog_append,
	const Resource& reflog,
	const String& id,
	const Resource& committer,
	const String& msg);

int64_t HHVM_FUNCTION(git_reflog_append_to,
	const Resource& repo,
	const String& name,
	const String& id,
	const Resource& committer,
	const String& msg);

int64_t HHVM_FUNCTION(git_reflog_rename,
	const Resource& repo,
	const String& old_name,
	const String& name);

int64_t HHVM_FUNCTION(git_reflog_delete,
	const Resource& repo,
	const String& name);

int64_t HHVM_FUNCTION(git_reflog_entrycount,
	const Resource& reflog);

Resource HHVM_FUNCTION(git_reflog_entry_byindex,
	const Resource& reflog,
	int64_t idx);

int64_t HHVM_FUNCTION(git_reflog_drop,
	const Resource& reflog,
	int64_t idx,
	int64_t rewrite_previous_entry);

String HHVM_FUNCTION(git_reflog_entry_id_old,
	const Resource& entry);

String HHVM_FUNCTION(git_reflog_entry_id_new,
	const Resource& entry);

Resource HHVM_FUNCTION(git_reflog_entry_committer,
	const Resource& entry);

String HHVM_FUNCTION(git_reflog_entry_message,
	const Resource& entry);

void HHVM_FUNCTION(git_reflog_free,
	const Resource& reflog);

#endif

