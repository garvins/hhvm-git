/*
 * Copyright (C) the hhvm-git contributors. All rights reserved.
 *
 * This file is part of hhvm-git, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included LICENSE file.
 */

#ifndef HHVM_GIT2_REFSPEC_H
#define HHVM_GIT2_REFSPEC_H


using namespace HPHP;

String HHVM_FUNCTION(git_refspec_src,
	const Resource& refspec);

String HHVM_FUNCTION(git_refspec_dst,
	const Resource& refspec);

String HHVM_FUNCTION(git_refspec_string,
	const Resource& refspec);

int64_t HHVM_FUNCTION(git_refspec_force,
	const Resource& refspec);

int64_t HHVM_FUNCTION(git_refspec_direction,
	const Resource& spec);

int64_t HHVM_FUNCTION(git_refspec_src_matches,
	const Resource& refspec,
	const String& refname);

int64_t HHVM_FUNCTION(git_refspec_dst_matches,
	const Resource& refspec,
	const String& refname);

String HHVM_FUNCTION(git_refspec_transform,
	int64_t outlen,
	const Resource& spec,
	const String& name);

String HHVM_FUNCTION(git_refspec_rtransform,
	int64_t outlen,
	const Resource& spec,
	const String& name);

#endif

