/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_NOTES_H
#define HHVM_GIT2_NOTES_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_note_iterator_new,
	const Resource& repo,
	const String& notes_ref);

void HHVM_FUNCTION(git_note_iterator_free,
	const Resource& it);

String HHVM_FUNCTION(git_note_next,
	const String& annotated_id,
	const Resource& it);

Resource HHVM_FUNCTION(git_note_read,
	const Resource& repo,
	const String& notes_ref,
	const String& oid);

String HHVM_FUNCTION(git_note_message,
	const Resource& note);

String HHVM_FUNCTION(git_note_oid,
	const Resource& note);

String HHVM_FUNCTION(git_note_create,
	const Resource& repo,
	const Resource& author,
	const Resource& committer,
	const String& notes_ref,
	const String& oid,
	const String& note,
	int64_t force);

int64_t HHVM_FUNCTION(git_note_remove,
	const Resource& repo,
	const String& notes_ref,
	const Resource& author,
	const Resource& committer,
	const String& oid);

void HHVM_FUNCTION(git_note_free,
	const Resource& note);

String HHVM_FUNCTION(git_note_default_ref,
	const Resource& repo);

int64_t HHVM_FUNCTION(git_note_foreach,
	const Resource& repo,
	const String& notes_ref,
	const Variant& note_cb,
	const Variant& payload);

#endif

