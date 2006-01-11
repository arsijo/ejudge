/* -*- c -*- */
/* $Id$ */

#ifndef __SUPER_PROTO_H__
#define __SUPER_PROTO_H__

/* Copyright (C) 2004-2006 Alexander Chernov <cher@ispras.ru> */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#define PROT_SUPER_PACKET_MAGIC (0xf249)
struct prot_super_packet
{
  unsigned short magic;
  short id;
};

/* client-server requests */
enum
{
  SSERV_CMD_PASS_FD = 1,
  SSERV_CMD_MAIN_PAGE,
  SSERV_CMD_CONTEST_PAGE,
  SSERV_CMD_VIEW_SERVE_LOG,
  SSERV_CMD_VIEW_RUN_LOG,
  SSERV_CMD_VIEW_CONTEST_XML,
  SSERV_CMD_VIEW_SERVE_CFG,
  SSERV_CMD_OPEN_CONTEST,
  SSERV_CMD_CLOSE_CONTEST,
  SSERV_CMD_INVISIBLE_CONTEST,
  SSERV_CMD_VISIBLE_CONTEST,
  SSERV_CMD_SHOW_HIDDEN,
  SSERV_CMD_HIDE_HIDDEN,
  SSERV_CMD_SHOW_CLOSED,
  SSERV_CMD_HIDE_CLOSED,
  SSERV_CMD_SHOW_UNMNG,
  SSERV_CMD_HIDE_UNMNG,

  SSERV_CMD_SERVE_LOG_TRUNC,
  SSERV_CMD_SERVE_LOG_DEV_NULL,
  SSERV_CMD_SERVE_LOG_FILE,
  SSERV_CMD_RUN_LOG_TRUNC,
  SSERV_CMD_RUN_LOG_DEV_NULL,
  SSERV_CMD_RUN_LOG_FILE,
  SSERV_CMD_SERVE_MNG_TERM,
  SSERV_CMD_RUN_MNG_TERM,
  SSERV_CMD_CONTEST_RESTART,
  SSERV_CMD_CLEAR_MESSAGES,

  SSERV_CMD_SERVE_MNG_RESET_ERROR,
  SSERV_CMD_SERVE_MNG_PROBE_RUN,
  SSERV_CMD_RUN_MNG_RESET_ERROR,

  SSERV_CMD_CREATE_CONTEST,
  SSERV_CMD_CREATE_CONTEST_2,
  SSERV_CMD_EDIT_CURRENT_CONTEST,
  SSERV_CMD_CNTS_BASIC_VIEW,
  SSERV_CMD_CNTS_ADVANCED_VIEW,
  SSERV_CMD_CNTS_SHOW_HTML_HEADERS,
  SSERV_CMD_CNTS_HIDE_HTML_HEADERS,
  SSERV_CMD_CNTS_SHOW_HTML_ATTRS,
  SSERV_CMD_CNTS_HIDE_HTML_ATTRS,
  SSERV_CMD_CNTS_FORGET,
  SSERV_CMD_CNTS_SHOW_PATHS,
  SSERV_CMD_CNTS_HIDE_PATHS,
  SSERV_CMD_CNTS_SHOW_NOTIFICATIONS,
  SSERV_CMD_CNTS_HIDE_NOTIFICATIONS,
  SSERV_CMD_CNTS_SHOW_ACCESS_RULES,
  SSERV_CMD_CNTS_HIDE_ACCESS_RULES,
  SSERV_CMD_EDIT_REGISTER_ACCESS,
  SSERV_CMD_EDIT_USERS_ACCESS,
  SSERV_CMD_EDIT_MASTER_ACCESS,
  SSERV_CMD_EDIT_JUDGE_ACCESS,
  SSERV_CMD_EDIT_TEAM_ACCESS,
  SSERV_CMD_EDIT_SERVE_CONTROL_ACCESS,
  SSERV_CMD_CNTS_SHOW_PERMISSIONS,
  SSERV_CMD_CNTS_HIDE_PERMISSIONS,
  SSERV_CMD_EDIT_CONTEST_XML,
  SSERV_CMD_CHECK_TESTS,
  SSERV_CMD_CNTS_EDIT_PERMISSION,
  SSERV_CMD_CNTS_SHOW_FORM_FIELDS,
  SSERV_CMD_CNTS_HIDE_FORM_FIELDS,
  SSERV_CMD_CNTS_EDIT_FORM_FIELDS,
  SSERV_CMD_CNTS_EDIT_CONTESTANT_FIELDS,
  SSERV_CMD_CNTS_EDIT_RESERVE_FIELDS,
  SSERV_CMD_CNTS_EDIT_COACH_FIELDS,
  SSERV_CMD_CNTS_EDIT_ADVISOR_FIELDS,
  SSERV_CMD_CNTS_EDIT_GUEST_FIELDS,
  SSERV_CMD_CNTS_EDIT_USERS_HEADER,
  SSERV_CMD_CNTS_EDIT_USERS_FOOTER,
  SSERV_CMD_CNTS_EDIT_REGISTER_HEADER,
  SSERV_CMD_CNTS_EDIT_REGISTER_FOOTER,
  SSERV_CMD_CNTS_EDIT_TEAM_HEADER,
  SSERV_CMD_CNTS_EDIT_TEAM_FOOTER,
  SSERV_CMD_CNTS_EDIT_REGISTER_EMAIL_FILE,

  SSERV_CMD_CNTS_CLEAR_NAME,
  SSERV_CMD_CNTS_CLEAR_NAME_EN,
  SSERV_CMD_CNTS_CLEAR_DEADLINE,
  SSERV_CMD_CNTS_CLEAR_USERS_HEADER,
  SSERV_CMD_CNTS_CLEAR_USERS_FOOTER,
  SSERV_CMD_CNTS_CLEAR_REGISTER_HEADER,
  SSERV_CMD_CNTS_CLEAR_REGISTER_FOOTER,
  SSERV_CMD_CNTS_CLEAR_TEAM_HEADER,
  SSERV_CMD_CNTS_CLEAR_TEAM_FOOTER,
  SSERV_CMD_CNTS_CLEAR_USERS_HEAD_STYLE,
  SSERV_CMD_CNTS_CLEAR_USERS_PAR_STYLE,
  SSERV_CMD_CNTS_CLEAR_USERS_TABLE_STYLE,
  SSERV_CMD_CNTS_CLEAR_USERS_VERB_STYLE,
  SSERV_CMD_CNTS_CLEAR_USERS_TABLE_FORMAT,
  SSERV_CMD_CNTS_CLEAR_USERS_TABLE_FORMAT_EN,
  SSERV_CMD_CNTS_CLEAR_USERS_TABLE_LEGEND,
  SSERV_CMD_CNTS_CLEAR_USERS_TABLE_LEGEND_EN,
  SSERV_CMD_CNTS_CLEAR_REGISTER_HEAD_STYLE,
  SSERV_CMD_CNTS_CLEAR_REGISTER_PAR_STYLE,
  SSERV_CMD_CNTS_CLEAR_REGISTER_TABLE_STYLE,
  SSERV_CMD_CNTS_CLEAR_REGISTER_NAME_COMMENT,
  SSERV_CMD_CNTS_CLEAR_ALLOWED_LANGUAGES,
  SSERV_CMD_CNTS_CLEAR_CF_NOTIFY_EMAIL,
  SSERV_CMD_CNTS_CLEAR_CLAR_NOTIFY_EMAIL,
  SSERV_CMD_CNTS_CLEAR_DAYLY_STAT_EMAIL,
  SSERV_CMD_CNTS_CLEAR_TEAM_HEAD_STYLE,
  SSERV_CMD_CNTS_CLEAR_TEAM_PAR_STYLE,
  SSERV_CMD_CNTS_CLEAR_REGISTER_EMAIL,
  SSERV_CMD_CNTS_CLEAR_REGISTER_URL,
  SSERV_CMD_CNTS_CLEAR_REGISTER_EMAIL_FILE,
  SSERV_CMD_CNTS_CLEAR_TEAM_URL,
  SSERV_CMD_CNTS_CLEAR_STANDINGS_URL,
  SSERV_CMD_CNTS_CLEAR_PROBLEMS_URL,
  SSERV_CMD_CNTS_CLEAR_ROOT_DIR,
  SSERV_CMD_CNTS_CLEAR_CONF_DIR,

  SSERV_CMD_CNTS_CHANGE_NAME,
  SSERV_CMD_CNTS_CHANGE_NAME_EN,
  SSERV_CMD_CNTS_CHANGE_AUTOREGISTER,
  SSERV_CMD_CNTS_CHANGE_TEAM_PASSWD,
  SSERV_CMD_CNTS_CHANGE_MANAGED,
  SSERV_CMD_CNTS_CHANGE_RUN_MANAGED,
  SSERV_CMD_CNTS_CHANGE_CLEAN_USERS,
  SSERV_CMD_CNTS_CHANGE_CLOSED,
  SSERV_CMD_CNTS_CHANGE_INVISIBLE,
  SSERV_CMD_CNTS_CHANGE_TIME_SKEW,
  SSERV_CMD_CNTS_CHANGE_TEAM_LOGIN,
  SSERV_CMD_CNTS_CHANGE_MEMBER_DELETE,
  SSERV_CMD_CNTS_CHANGE_DEADLINE,
  SSERV_CMD_CNTS_CHANGE_USERS_HEADER,
  SSERV_CMD_CNTS_CHANGE_USERS_FOOTER,
  SSERV_CMD_CNTS_CHANGE_REGISTER_HEADER,
  SSERV_CMD_CNTS_CHANGE_REGISTER_FOOTER,
  SSERV_CMD_CNTS_CHANGE_TEAM_HEADER,
  SSERV_CMD_CNTS_CHANGE_TEAM_FOOTER,
  SSERV_CMD_CNTS_CHANGE_USERS_HEAD_STYLE,
  SSERV_CMD_CNTS_CHANGE_USERS_PAR_STYLE,
  SSERV_CMD_CNTS_CHANGE_USERS_TABLE_STYLE,
  SSERV_CMD_CNTS_CHANGE_USERS_VERB_STYLE,
  SSERV_CMD_CNTS_CHANGE_USERS_TABLE_FORMAT,
  SSERV_CMD_CNTS_CHANGE_USERS_TABLE_FORMAT_EN,
  SSERV_CMD_CNTS_CHANGE_USERS_TABLE_LEGEND,
  SSERV_CMD_CNTS_CHANGE_USERS_TABLE_LEGEND_EN,
  SSERV_CMD_CNTS_CHANGE_REGISTER_HEAD_STYLE,
  SSERV_CMD_CNTS_CHANGE_REGISTER_PAR_STYLE,
  SSERV_CMD_CNTS_CHANGE_REGISTER_TABLE_STYLE,
  SSERV_CMD_CNTS_CHANGE_REGISTER_NAME_COMMENT,
  SSERV_CMD_CNTS_CHANGE_ALLOWED_LANGUAGES,
  SSERV_CMD_CNTS_CHANGE_CF_NOTIFY_EMAIL,
  SSERV_CMD_CNTS_CHANGE_CLAR_NOTIFY_EMAIL,
  SSERV_CMD_CNTS_CHANGE_DAYLY_STAT_EMAIL,
  SSERV_CMD_CNTS_CHANGE_TEAM_HEAD_STYLE,
  SSERV_CMD_CNTS_CHANGE_TEAM_PAR_STYLE,
  SSERV_CMD_CNTS_CHANGE_REGISTER_EMAIL,
  SSERV_CMD_CNTS_CHANGE_REGISTER_URL,
  SSERV_CMD_CNTS_CHANGE_REGISTER_EMAIL_FILE,
  SSERV_CMD_CNTS_CHANGE_TEAM_URL,
  SSERV_CMD_CNTS_CHANGE_STANDINGS_URL,
  SSERV_CMD_CNTS_CHANGE_PROBLEMS_URL,
  SSERV_CMD_CNTS_CHANGE_ROOT_DIR,
  SSERV_CMD_CNTS_CHANGE_CONF_DIR,
  SSERV_CMD_CNTS_DEFAULT_ACCESS,
  SSERV_CMD_CNTS_ADD_RULE,
  SSERV_CMD_CNTS_CHANGE_RULE,
  SSERV_CMD_CNTS_DELETE_RULE,
  SSERV_CMD_CNTS_UP_RULE,
  SSERV_CMD_CNTS_DOWN_RULE,
  SSERV_CMD_CNTS_COPY_ACCESS,
  SSERV_CMD_CNTS_DELETE_PERMISSION,
  SSERV_CMD_CNTS_ADD_PERMISSION,
  SSERV_CMD_CNTS_SAVE_PERMISSIONS,
  SSERV_CMD_CNTS_SAVE_FORM_FIELDS,
  SSERV_CMD_CNTS_SAVE_CONTESTANT_FIELDS, /* NOTE: the following 5 commands must */
  SSERV_CMD_CNTS_SAVE_RESERVE_FIELDS,    /* be sequental */
  SSERV_CMD_CNTS_SAVE_COACH_FIELDS,
  SSERV_CMD_CNTS_SAVE_ADVISOR_FIELDS,
  SSERV_CMD_CNTS_SAVE_GUEST_FIELDS,
  SSERV_CMD_CNTS_SAVE_USERS_HEADER,
  SSERV_CMD_CNTS_SAVE_USERS_FOOTER,
  SSERV_CMD_CNTS_SAVE_REGISTER_HEADER,
  SSERV_CMD_CNTS_SAVE_REGISTER_FOOTER,
  SSERV_CMD_CNTS_SAVE_TEAM_HEADER,
  SSERV_CMD_CNTS_SAVE_TEAM_FOOTER,
  SSERV_CMD_CNTS_SAVE_REGISTER_EMAIL_FILE,
  SSERV_CMD_CNTS_CLEAR_USERS_HEADER_TEXT,
  SSERV_CMD_CNTS_CLEAR_USERS_FOOTER_TEXT,
  SSERV_CMD_CNTS_CLEAR_REGISTER_HEADER_TEXT,
  SSERV_CMD_CNTS_CLEAR_REGISTER_FOOTER_TEXT,
  SSERV_CMD_CNTS_CLEAR_TEAM_HEADER_TEXT,
  SSERV_CMD_CNTS_CLEAR_TEAM_FOOTER_TEXT,
  SSERV_CMD_CNTS_CLEAR_REGISTER_EMAIL_FILE_TEXT,
  SSERV_CMD_CNTS_COMMIT,

  SSERV_CMD_EDIT_CURRENT_GLOBAL,
  SSERV_CMD_GLOB_SHOW_1,
  SSERV_CMD_GLOB_HIDE_1,
  SSERV_CMD_GLOB_SHOW_2,
  SSERV_CMD_GLOB_HIDE_2,
  SSERV_CMD_GLOB_SHOW_3,
  SSERV_CMD_GLOB_HIDE_3,
  SSERV_CMD_GLOB_SHOW_4,
  SSERV_CMD_GLOB_HIDE_4,
  SSERV_CMD_GLOB_SHOW_5,
  SSERV_CMD_GLOB_HIDE_5,
  SSERV_CMD_GLOB_SHOW_6,
  SSERV_CMD_GLOB_HIDE_6,
  SSERV_CMD_GLOB_SHOW_7,
  SSERV_CMD_GLOB_HIDE_7,

  SSERV_CMD_EDIT_CURRENT_LANG,
  SSERV_CMD_LANG_SHOW_DETAILS,
  SSERV_CMD_LANG_HIDE_DETAILS,
  SSERV_CMD_LANG_DEACTIVATE,
  SSERV_CMD_LANG_ACTIVATE,
  
  SSERV_CMD_EDIT_CURRENT_PROB,
  SSERV_CMD_PROB_ADD_ABSTRACT,
  SSERV_CMD_PROB_ADD,
  SSERV_CMD_PROB_SHOW_DETAILS,
  SSERV_CMD_PROB_HIDE_DETAILS,
  SSERV_CMD_PROB_SHOW_ADVANCED,
  SSERV_CMD_PROB_HIDE_ADVANCED,

  SSERV_CMD_GLOB_CHANGE_DURATION,
  SSERV_CMD_GLOB_UNLIMITED_DURATION,
  SSERV_CMD_GLOB_CHANGE_TYPE,
  SSERV_CMD_GLOB_CHANGE_FOG_TIME,
  SSERV_CMD_GLOB_CHANGE_UNFOG_TIME,
  SSERV_CMD_GLOB_DISABLE_FOG,
  SSERV_CMD_GLOB_CHANGE_STAND_LOCALE,
  SSERV_CMD_GLOB_CHANGE_SRC_VIEW,
  SSERV_CMD_GLOB_CHANGE_REP_VIEW,
  SSERV_CMD_GLOB_CHANGE_CE_VIEW,
  SSERV_CMD_GLOB_CHANGE_JUDGE_REPORT,
  SSERV_CMD_GLOB_CHANGE_DISABLE_CLARS,
  SSERV_CMD_GLOB_CHANGE_DISABLE_TEAM_CLARS,
  SSERV_CMD_GLOB_CHANGE_DISABLE_SUBMIT_AFTER_OK,
  SSERV_CMD_GLOB_CHANGE_IGNORE_COMPILE_ERRORS,
  SSERV_CMD_GLOB_CHANGE_IGNORE_DUPICATED_RUNS,
  SSERV_CMD_GLOB_CHANGE_REPORT_ERROR_CODE,
  SSERV_CMD_GLOB_CHANGE_SHOW_DEADLINE,
  SSERV_CMD_GLOB_CHANGE_ENABLE_PRINTING,
  SSERV_CMD_GLOB_CHANGE_PRUNE_EMPTY_USERS,
  SSERV_CMD_GLOB_CHANGE_ENABLE_FULL_ARCHIVE,
  SSERV_CMD_GLOB_CHANGE_TEST_DIR,
  SSERV_CMD_GLOB_CLEAR_TEST_DIR,
  SSERV_CMD_GLOB_CHANGE_CORR_DIR,
  SSERV_CMD_GLOB_CLEAR_CORR_DIR,
  SSERV_CMD_GLOB_CHANGE_INFO_DIR,
  SSERV_CMD_GLOB_CLEAR_INFO_DIR,
  SSERV_CMD_GLOB_CHANGE_TGZ_DIR,
  SSERV_CMD_GLOB_CLEAR_TGZ_DIR,
  SSERV_CMD_GLOB_CHANGE_CHECKER_DIR,
  SSERV_CMD_GLOB_CLEAR_CHECKER_DIR,
  SSERV_CMD_GLOB_CHANGE_CONTEST_START_CMD,
  SSERV_CMD_GLOB_CLEAR_CONTEST_START_CMD,
  SSERV_CMD_GLOB_EDIT_CONTEST_START_CMD,
  SSERV_CMD_GLOB_CHANGE_MAX_RUN_SIZE,
  SSERV_CMD_GLOB_CHANGE_MAX_RUN_TOTAL,
  SSERV_CMD_GLOB_CHANGE_MAX_RUN_NUM,
  SSERV_CMD_GLOB_CHANGE_MAX_CLAR_SIZE,
  SSERV_CMD_GLOB_CHANGE_MAX_CLAR_TOTAL,
  SSERV_CMD_GLOB_CHANGE_MAX_CLAR_NUM,
  SSERV_CMD_GLOB_CHANGE_TEAM_PAGE_QUOTA,
  SSERV_CMD_GLOB_CHANGE_TEAM_INFO_URL,
  SSERV_CMD_GLOB_CLEAR_TEAM_INFO_URL,
  SSERV_CMD_GLOB_CHANGE_PROB_INFO_URL,
  SSERV_CMD_GLOB_CLEAR_PROB_INFO_URL,
  SSERV_CMD_GLOB_CHANGE_STAND_FILE_NAME,
  SSERV_CMD_GLOB_CLEAR_STAND_FILE_NAME,
  SSERV_CMD_GLOB_CHANGE_USERS_ON_PAGE,
  SSERV_CMD_GLOB_CHANGE_STAND_HEADER_FILE,
  SSERV_CMD_GLOB_CLEAR_STAND_HEADER_FILE,
  SSERV_CMD_GLOB_EDIT_STAND_HEADER_FILE,
  SSERV_CMD_GLOB_CHANGE_STAND_FOOTER_FILE,
  SSERV_CMD_GLOB_CLEAR_STAND_FOOTER_FILE,
  SSERV_CMD_GLOB_EDIT_STAND_FOOTER_FILE,
  SSERV_CMD_GLOB_CHANGE_STAND_SYMLINK_DIR,
  SSERV_CMD_GLOB_CLEAR_STAND_SYMLINK_DIR,
  SSERV_CMD_GLOB_CHANGE_STAND_IGNORE_AFTER,
  SSERV_CMD_GLOB_CLEAR_STAND_IGNORE_AFTER,
  SSERV_CMD_GLOB_CHANGE_ENABLE_STAND2,
  SSERV_CMD_GLOB_CHANGE_STAND2_FILE_NAME,
  SSERV_CMD_GLOB_CLEAR_STAND2_FILE_NAME,
  SSERV_CMD_GLOB_CHANGE_STAND2_HEADER_FILE,
  SSERV_CMD_GLOB_CLEAR_STAND2_HEADER_FILE,
  SSERV_CMD_GLOB_EDIT_STAND2_HEADER_FILE,
  SSERV_CMD_GLOB_CHANGE_STAND2_FOOTER_FILE,
  SSERV_CMD_GLOB_CLEAR_STAND2_FOOTER_FILE,
  SSERV_CMD_GLOB_EDIT_STAND2_FOOTER_FILE,
  SSERV_CMD_GLOB_CHANGE_STAND2_SYMLINK_DIR,
  SSERV_CMD_GLOB_CLEAR_STAND2_SYMLINK_DIR,
  SSERV_CMD_GLOB_CHANGE_ENABLE_PLOG,
  SSERV_CMD_GLOB_CHANGE_PLOG_FILE_NAME,
  SSERV_CMD_GLOB_CLEAR_PLOG_FILE_NAME,
  SSERV_CMD_GLOB_CHANGE_PLOG_HEADER_FILE,
  SSERV_CMD_GLOB_CLEAR_PLOG_HEADER_FILE,
  SSERV_CMD_GLOB_EDIT_PLOG_HEADER_FILE,
  SSERV_CMD_GLOB_CHANGE_PLOG_FOOTER_FILE,
  SSERV_CMD_GLOB_CLEAR_PLOG_FOOTER_FILE,
  SSERV_CMD_GLOB_EDIT_PLOG_FOOTER_FILE,
  SSERV_CMD_GLOB_CHANGE_PLOG_SYMLINK_DIR,
  SSERV_CMD_GLOB_CLEAR_PLOG_SYMLINK_DIR,
  SSERV_CMD_GLOB_CHANGE_PLOG_UPDATE_TIME,
  SSERV_CMD_GLOB_CHANGE_STAND_TABLE_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_TABLE_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_PLACE_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_PLACE_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_TEAM_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_TEAM_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_PROB_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_PROB_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_SOLVED_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_SOLVED_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_SCORE_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_SCORE_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_PENALTY_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_PENALTY_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_SHOW_OK_TIME,
  SSERV_CMD_GLOB_CHANGE_STAND_SHOW_ATT_NUM,
  SSERV_CMD_GLOB_CHANGE_STAND_SORT_BY_SOLVED,
  SSERV_CMD_GLOB_CHANGE_IGNORE_SUCCESS_TIME,
  SSERV_CMD_GLOB_CHANGE_STAND_TIME_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_TIME_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_SUCCESS_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_SUCCESS_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_FAIL_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_FAIL_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_TRANS_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_TRANS_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_SELF_ROW_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_SELF_ROW_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_V_ROW_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_V_ROW_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_R_ROW_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_R_ROW_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_U_ROW_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_U_ROW_ATTR,
  SSERV_CMD_GLOB_CHANGE_ENABLE_EXTRA_COL,
  SSERV_CMD_GLOB_CHANGE_STAND_EXTRA_FORMAT,
  SSERV_CMD_GLOB_CLEAR_STAND_EXTRA_FORMAT,
  SSERV_CMD_GLOB_CHANGE_STAND_EXTRA_LEGEND,
  SSERV_CMD_GLOB_CLEAR_STAND_EXTRA_LEGEND,
  SSERV_CMD_GLOB_CHANGE_STAND_EXTRA_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_EXTRA_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_SHOW_WARN_NUMBER,
  SSERV_CMD_GLOB_CHANGE_STAND_WARN_NUMBER_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_WARN_NUMBER_ATTR,
  SSERV_CMD_GLOB_CHANGE_SLEEP_TIME,
  SSERV_CMD_GLOB_CHANGE_SERVE_SLEEP_TIME,
  SSERV_CMD_GLOB_CHANGE_AUTOUPDATE_STANDINGS,
  SSERV_CMD_GLOB_CHANGE_ROUNDING_MODE,
  SSERV_CMD_GLOB_CHANGE_MAX_FILE_LENGTH,
  SSERV_CMD_GLOB_CHANGE_MAX_LINE_LENGTH,
  SSERV_CMD_GLOB_CHANGE_INACTIVITY_TIMEOUT,
  SSERV_CMD_GLOB_CHANGE_DISABLE_AUTO_TESTING,
  SSERV_CMD_GLOB_CHANGE_DISABLE_TESTING,
  SSERV_CMD_GLOB_CHANGE_CR_SERIALIZATION_KEY,
  SSERV_CMD_GLOB_CHANGE_SHOW_ASTR_TIME,
  SSERV_CMD_GLOB_CHANGE_ENABLE_CONTINUE,
  SSERV_CMD_GLOB_CHANGE_ENABLE_REPORT_UPLOAD,
  SSERV_CMD_GLOB_CHANGE_ENABLE_RUNLOG_MERGE,
  SSERV_CMD_GLOB_CHANGE_USE_COMPILATION_SERVER,
  SSERV_CMD_GLOB_CHANGE_ENABLE_L10N,
  SSERV_CMD_GLOB_CHANGE_CHARSET,
  SSERV_CMD_GLOB_CLEAR_CHARSET,
  SSERV_CMD_GLOB_CHANGE_TEAM_DOWNLOAD_TIME,
  SSERV_CMD_GLOB_DISABLE_TEAM_DOWNLOAD_TIME,
  SSERV_CMD_GLOB_CHANGE_CPU_BOGOMIPS,
  SSERV_CMD_GLOB_DETECT_CPU_BOGOMIPS,
  SSERV_CMD_GLOB_CHANGE_SECURE_RUN,
  SSERV_CMD_GLOB_CHANGE_ENABLE_MEMORY_LIMIT_ERROR,
  SSERV_CMD_GLOB_CHANGE_STAND_ROW_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_ROW_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_PAGE_TABLE_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_PAGE_TABLE_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_PAGE_CUR_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_PAGE_CUR_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_PAGE_ROW_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_PAGE_ROW_ATTR,
  SSERV_CMD_GLOB_CHANGE_STAND_PAGE_COL_ATTR,
  SSERV_CMD_GLOB_CLEAR_STAND_PAGE_COL_ATTR,

  SSERV_CMD_LANG_CHANGE_DISABLED,
  SSERV_CMD_LANG_CHANGE_LONG_NAME,
  SSERV_CMD_LANG_CLEAR_LONG_NAME,
  SSERV_CMD_LANG_CHANGE_DISABLE_AUTO_TESTING,
  SSERV_CMD_LANG_CHANGE_DISABLE_TESTING,
  SSERV_CMD_LANG_CHANGE_OPTS,
  SSERV_CMD_LANG_CLEAR_OPTS,

  SSERV_CMD_PROB_DELETE,
  SSERV_CMD_PROB_CHANGE_SHORT_NAME,
  SSERV_CMD_PROB_CLEAR_SHORT_NAME,
  SSERV_CMD_PROB_CHANGE_LONG_NAME,
  SSERV_CMD_PROB_CLEAR_LONG_NAME,
  SSERV_CMD_PROB_CHANGE_SUPER,
  SSERV_CMD_PROB_CHANGE_USE_STDIN,
  SSERV_CMD_PROB_CHANGE_USE_STDOUT,
  SSERV_CMD_PROB_CHANGE_BINARY_INPUT,
  SSERV_CMD_PROB_CHANGE_TIME_LIMIT,
  SSERV_CMD_PROB_CHANGE_TIME_LIMIT_MILLIS,
  SSERV_CMD_PROB_CHANGE_REAL_TIME_LIMIT,
  SSERV_CMD_PROB_CHANGE_TEAM_ENABLE_REP_VIEW,
  SSERV_CMD_PROB_CHANGE_TEAM_ENABLE_CE_VIEW,
  SSERV_CMD_PROB_CHANGE_TEAM_SHOW_JUDGE_REPORT,
  SSERV_CMD_PROB_CHANGE_DISABLE_TESTING,
  SSERV_CMD_PROB_CHANGE_DISABLE_AUTO_TESTING,
  SSERV_CMD_PROB_CHANGE_ENABLE_COMPILATION,
  SSERV_CMD_PROB_CHANGE_FULL_SCORE,
  SSERV_CMD_PROB_CHANGE_TEST_SCORE,
  SSERV_CMD_PROB_CHANGE_RUN_PENALTY,
  SSERV_CMD_PROB_CHANGE_DISQUALIFIED_PENALTY,
  SSERV_CMD_PROB_CHANGE_VARIABLE_FULL_SCORE,
  SSERV_CMD_PROB_CHANGE_TEST_SCORE_LIST,
  SSERV_CMD_PROB_CLEAR_TEST_SCORE_LIST,
  SSERV_CMD_PROB_CHANGE_SCORE_TESTS,
  SSERV_CMD_PROB_CLEAR_SCORE_TESTS,
  SSERV_CMD_PROB_CHANGE_TESTS_TO_ACCEPT,
  SSERV_CMD_PROB_CHANGE_ACCEPT_PARTIAL,
  SSERV_CMD_PROB_CHANGE_HIDDEN,
  SSERV_CMD_PROB_CHANGE_STAND_HIDE_TIME,
  SSERV_CMD_PROB_CHANGE_CHECKER_REAL_TIME_LIMIT,
  SSERV_CMD_PROB_CHANGE_MAX_VM_SIZE,
  SSERV_CMD_PROB_CHANGE_MAX_STACK_SIZE,
  SSERV_CMD_PROB_CHANGE_INPUT_FILE,
  SSERV_CMD_PROB_CLEAR_INPUT_FILE,
  SSERV_CMD_PROB_CHANGE_OUTPUT_FILE,
  SSERV_CMD_PROB_CLEAR_OUTPUT_FILE,
  SSERV_CMD_PROB_CHANGE_USE_CORR,
  SSERV_CMD_PROB_CHANGE_USE_INFO,
  SSERV_CMD_PROB_CHANGE_TEST_DIR,
  SSERV_CMD_PROB_CLEAR_TEST_DIR,
  SSERV_CMD_PROB_CHANGE_CORR_DIR,
  SSERV_CMD_PROB_CLEAR_CORR_DIR,
  SSERV_CMD_PROB_CHANGE_INFO_DIR,
  SSERV_CMD_PROB_CLEAR_INFO_DIR,
  SSERV_CMD_PROB_CHANGE_TEST_SFX,
  SSERV_CMD_PROB_CLEAR_TEST_SFX,
  SSERV_CMD_PROB_CHANGE_TEST_PAT,
  SSERV_CMD_PROB_CLEAR_TEST_PAT,
  SSERV_CMD_PROB_CHANGE_CORR_SFX,
  SSERV_CMD_PROB_CLEAR_CORR_SFX,
  SSERV_CMD_PROB_CHANGE_CORR_PAT,
  SSERV_CMD_PROB_CLEAR_CORR_PAT,
  SSERV_CMD_PROB_CHANGE_INFO_SFX,
  SSERV_CMD_PROB_CLEAR_INFO_SFX,
  SSERV_CMD_PROB_CHANGE_INFO_PAT,
  SSERV_CMD_PROB_CLEAR_INFO_PAT,
  SSERV_CMD_PROB_CHANGE_STANDARD_CHECKER,
  SSERV_CMD_PROB_CHANGE_SCORE_BONUS,
  SSERV_CMD_PROB_CLEAR_SCORE_BONUS,
  SSERV_CMD_PROB_CHANGE_CHECK_CMD,
  SSERV_CMD_PROB_CLEAR_CHECK_CMD,
  SSERV_CMD_PROB_CHANGE_CHECKER_ENV,
  SSERV_CMD_PROB_CLEAR_CHECKER_ENV,
  SSERV_CMD_PROB_CHANGE_LANG_TIME_ADJ,
  SSERV_CMD_PROB_CLEAR_LANG_TIME_ADJ,
  SSERV_CMD_PROB_CHANGE_START_DATE,
  SSERV_CMD_PROB_CLEAR_START_DATE,
  SSERV_CMD_PROB_CHANGE_DEADLINE,
  SSERV_CMD_PROB_CLEAR_DEADLINE,
  SSERV_CMD_PROB_CHANGE_VARIANT_NUM,
  SSERV_CMD_PROB_EDIT_VARIANTS,
  SSERV_CMD_PROB_EDIT_VARIANTS_2,
  SSERV_CMD_PROB_CHANGE_VARIANTS,
  SSERV_CMD_PROB_DELETE_VARIANTS,

  SSERV_CMD_GLOB_SAVE_CONTEST_START_CMD,
  SSERV_CMD_GLOB_CLEAR_CONTEST_START_CMD_TEXT,
  SSERV_CMD_GLOB_SAVE_STAND_HEADER,
  SSERV_CMD_GLOB_CLEAR_STAND_HEADER_TEXT,
  SSERV_CMD_GLOB_SAVE_STAND_FOOTER,
  SSERV_CMD_GLOB_CLEAR_STAND_FOOTER_TEXT,
  SSERV_CMD_GLOB_SAVE_STAND2_HEADER,
  SSERV_CMD_GLOB_CLEAR_STAND2_HEADER_TEXT,
  SSERV_CMD_GLOB_SAVE_STAND2_FOOTER,
  SSERV_CMD_GLOB_CLEAR_STAND2_FOOTER_TEXT,
  SSERV_CMD_GLOB_SAVE_PLOG_HEADER,
  SSERV_CMD_GLOB_CLEAR_PLOG_HEADER_TEXT,
  SSERV_CMD_GLOB_SAVE_PLOG_FOOTER,
  SSERV_CMD_GLOB_CLEAR_PLOG_FOOTER_TEXT,

  SSERV_CMD_VIEW_NEW_SERVE_CFG,
  SSERV_CMD_LANG_UPDATE_VERSIONS,

  SSERV_CMD_LAST,
};

/* replies */
enum
{
  SSERV_RPL_OK = 0,

  SSERV_RPL_LAST,
};

/* error codes */
enum
{
  SSERV_ERR_NO_ERROR = 0,
  SSERV_ERR_1,                  /* to reserve -1 */
  SSERV_ERR_NOT_CONNECTED,
  SSERV_ERR_INVALID_FD,
  SSERV_ERR_WRITE_TO_SERVER,
  SSERV_ERR_BAD_SOCKET_NAME,
  SSERV_ERR_SYSTEM_ERROR,
  SSERV_ERR_CONNECT_FAILED,
  SSERV_ERR_READ_FROM_SERVER,
  SSERV_ERR_EOF_FROM_SERVER,
  SSERV_ERR_PROTOCOL_ERROR,
  SSERV_ERR_USERLIST_DOWN,
  SSERV_ERR_PERMISSION_DENIED,
  SSERV_ERR_INVALID_CONTEST,
  SSERV_ERR_BANNED_IP,
  SSERV_ERR_ROOT_DIR_NOT_SET,
  SSERV_ERR_FILE_NOT_EXIST,
  SSERV_ERR_LOG_IS_DEV_NULL,
  SSERV_ERR_FILE_READ_ERROR,
  SSERV_ERR_FILE_FORMAT_INVALID,
  SSERV_ERR_UNEXPECTED_USERLIST_ERROR,
  SSERV_ERR_CONTEST_ALREADY_USED,
  SSERV_ERR_CONTEST_EDITED,
  SSERV_ERR_NOT_IMPLEMENTED,
  SSERV_ERR_INVALID_PARAMETER,
  SSERV_ERR_CONTEST_NOT_EDITED,
  SSERV_ERR_DUPLICATED_LOGIN,
  SSERV_ERR_DUPLICATED_PROBLEM,
  SSERV_ERR_PROBLEM_IS_USED,

  SSERV_UNKNOWN_ERROR,
  SSERV_ERR_LAST,
};

unsigned char const *super_proto_strerror(int n);

enum
{
  SSERV_VIEW_INVISIBLE = 1,
};

struct prot_super_pkt_main_page
{
  struct prot_super_packet b;

  int locale_id;
  int contest_id;               /* for viewing contest details */
  unsigned int flags;           /* view flags */
  int self_url_len;
  int hidden_vars_len;
  int extra_args_len;
  unsigned char data[3];
};

struct prot_super_pkt_simple_cmd
{
  struct prot_super_packet b;

  int contest_id;
};

struct prot_super_pkt_create_contest
{
  struct prot_super_packet b;

  int num_mode;
  int templ_mode;
  int contest_id;
  int templ_id;
  int self_url_len;
  int hidden_vars_len;
  int extra_args_len;
  unsigned char data[3];
};

struct prot_super_pkt_set_param
{
  struct prot_super_packet b;

  int param1;
  int param2_len;
  int param3;
  int param4;
  int param5;
  unsigned char data[1];
};

#endif /* __SUPER_PROTO_H__ */
