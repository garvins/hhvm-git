/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_REMOTE_H
#define HHVM_GIT2_REMOTE_H

#include "../ext_git2.h"

using namespace HPHP;

Resource HHVM_FUNCTION(git_remote_create,
	const Resource& repo,
	const String& name,
	const String& url);

Resource HHVM_FUNCTION(git_remote_create_with_fetchspec,
	const Resource& repo,
	const String& name,
	const String& url,
	const String& fetch);

Resource HHVM_FUNCTION(git_remote_create_inmemory,
	const Resource& repo,
	const String& fetch,
	const String& url);

Resource HHVM_FUNCTION(git_remote_load,
	const Resource& repo,
	const String& name);

int64_t HHVM_FUNCTION(git_remote_save,
	const Resource& remote);

Resource HHVM_FUNCTION(git_remote_owner,
	const Resource& remote);

String HHVM_FUNCTION(git_remote_name,
	const Resource& remote);

String HHVM_FUNCTION(git_remote_url,
	const Resource& remote);

String HHVM_FUNCTION(git_remote_pushurl,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_remote_set_url,
	const Resource& remote,
	const String& url);

int64_t HHVM_FUNCTION(git_remote_set_pushurl,
	const Resource& remote,
	const String& url);

int64_t HHVM_FUNCTION(git_remote_add_fetch,
	const Resource& remote,
	const String& refspec);

int64_t HHVM_FUNCTION(git_remote_get_fetch_refspecs,
	const Resource& array,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_remote_set_fetch_refspecs,
	const Resource& remote,
	const Resource& array);

int64_t HHVM_FUNCTION(git_remote_add_push,
	const Resource& remote,
	const String& refspec);

int64_t HHVM_FUNCTION(git_remote_get_push_refspecs,
	const Resource& array,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_remote_set_push_refspecs,
	const Resource& remote,
	const Resource& array);

void HHVM_FUNCTION(git_remote_clear_refspecs,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_remote_refspec_count,
	const Resource& remote);

Resource HHVM_FUNCTION(git_remote_get_refspec,
	const Resource& remote,
	int64_t n);

int64_t HHVM_FUNCTION(git_remote_connect,
	const Resource& remote,
	int64_t direction);

Resource HHVM_FUNCTION(git_remote_ls,
	int64_t size,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_remote_download,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_remote_connected,
	const Resource& remote);

void HHVM_FUNCTION(git_remote_stop,
	const Resource& remote);

void HHVM_FUNCTION(git_remote_disconnect,
	const Resource& remote);

void HHVM_FUNCTION(git_remote_free,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_remote_update_tips,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_remote_fetch,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_remote_valid_url,
	const String& url);

int64_t HHVM_FUNCTION(git_remote_supported_url,
	const String& url);

Resource HHVM_FUNCTION(git_remote_list,
	const Resource& repo);

void HHVM_FUNCTION(git_remote_check_cert,
	const Resource& remote,
	int64_t check);

int64_t HHVM_FUNCTION(git_remote_set_transport,
	const Resource& remote,
	const Resource& transport);

int64_t HHVM_FUNCTION(git_remote_set_callbacks,
	const Resource& remote,
	const Array& callbacks);

Resource HHVM_FUNCTION(git_remote_stats,
	const Resource& remote);

int64_t HHVM_FUNCTION(git_remote_autotag,
	const Resource& remote);

void HHVM_FUNCTION(git_remote_set_autotag,
	const Resource& remote,
	int64_t value);

int64_t HHVM_FUNCTION(git_remote_rename,
	const Resource& remote,
	const String& new_name,
	const Variant& callback,
	const Variant& payload);

int64_t HHVM_FUNCTION(git_remote_update_fetchhead,
	const Resource& remote);

void HHVM_FUNCTION(git_remote_set_update_fetchhead,
	const Resource& remote,
	int64_t value);

int64_t HHVM_FUNCTION(git_remote_is_valid_name,
	const String& remote_name);

#endif

