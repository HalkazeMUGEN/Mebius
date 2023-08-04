/**
 * @file mugen.h
 * @author Halkaze
 * @brief WinMugenで使用されている構造体やグローバル変数, 主要関数の定義
 * @date 2023-03-17
 * @copyright Copyright (c) 2023
 *
 * allegro や JGMOD 由来のものはそれらのヘッダファイルを使えば何とかなると思われるので,
 * 極力載せない方針ですが, 単体でコンパイル可能にするために必要な箇所は定義しています.
 * allegro.h等と併用する場合は適宜重複する箇所を取り除いてやってください.
 *
 * crt由来のもの, 文字列,　定数は省略.
 *
 * 関数は取り急ぎ主要なもののみ定義.
 * 今後更新して増やすかも？
 *
 */

#ifndef __MUGEN_H__
#define __MUGEN_H__

#include <windows.h>

#include <stdint.h>
#include <stdio.h>

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef uint8_t undefined;
typedef uint8_t undefined1;
typedef uint16_t undefined2;
typedef uint32_t undefined4;
typedef uint64_t undefined8;

typedef union value32_t_ {
  int32_t i;
  uint32_t u;
  float f;
} value32_t;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef enum DIRECT_INPUT_KEYCODE_ {
  DIK_ESCAPE = 1,
  DIK_1 = 2,
  DIK_2 = 3,
  DIK_3 = 4,
  DIK_4 = 5,
  DIK_5 = 6,
  DIK_6 = 7,
  DIK_7 = 8,
  DIK_8 = 9,
  DIK_9 = 10,
  DIK_0 = 11,
  DIK_MINUS = 12,
  DIK_EQUALS = 13,
  DIK_BACK = 14,
  DIK_TAB = 15,
  DIK_Q = 16,
  DIK_W = 17,
  DIK_E = 18,
  DIK_R = 19,
  DIK_T = 20,
  DIK_Y = 21,
  DIK_U = 22,
  DIK_I = 23,
  DIK_O = 24,
  DIK_P = 25,
  DIK_LBRACKET = 26,
  DIK_RBRACKET = 27,
  DIK_RETURN = 28,
  DIK_LCONTROL = 29,
  DIK_A = 30,
  DIK_S = 31,
  DIK_D = 32,
  DIK_F = 33,
  DIK_G = 34,
  DIK_H = 35,
  DIK_J = 36,
  DIK_K = 37,
  DIK_L = 38,
  DIK_SEMICOLON = 39,
  DIK_APOSTROPHE = 40,
  DIK_GRAVE = 41,
  DIK_LSHIFT = 42,
  DIK_BACKSLASH = 43,
  DIK_Z = 44,
  DIK_X = 45,
  DIK_C = 46,
  DIK_V = 47,
  DIK_B = 48,
  DIK_N = 49,
  DIK_M = 50,
  DIK_COMMA = 51,
  DIK_PERIOD = 52,
  DIK_SLASH = 53,
  DIK_RSHIFT = 54,
  DIK_MULTIPLY = 55,
  DIK_LMENU = 56,
  DIK_SPACE = 57,
  DIK_CAPITAL = 58,
  DIK_F1 = 59,
  DIK_F2 = 60,
  DIK_F3 = 61,
  DIK_F4 = 62,
  DIK_F5 = 63,
  DIK_F6 = 64,
  DIK_F7 = 65,
  DIK_F8 = 66,
  DIK_F9 = 67,
  DIK_F10 = 68,
  DIK_NUMLOCK = 69,
  DIK_SCROLL = 70,
  DIK_NUMPAD7 = 71,
  DIK_NUMPAD8 = 72,
  DIK_NUMPAD9 = 73,
  DIK_SUBTRACT = 74,
  DIK_NUMPAD4 = 75,
  DIK_NUMPAD5 = 76,
  DIK_NUMPAD6 = 77,
  DIK_ADD = 78,
  DIK_NUMPAD1 = 79,
  DIK_NUMPAD2 = 80,
  DIK_NUMPAD3 = 81,
  DIK_NUMPAD0 = 82,
  DIK_DECIMAL = 83,
  DIK_F11 = 87,
  DIK_F12 = 88,
  DIK_F13 = 100,
  DIK_F14 = 101,
  DIK_F15 = 102,
  DIK_KANA = 112,
  DIK_CONVERT = 121,
  DIK_NOCONVERT = 123,
  DIK_YEN = 125,
  DIK_NUMPADEQUALS = 141,
  DIK_CIRCUMFLEX = 144,
  DIK_AT = 145,
  DIK_COLON = 146,
  DIK_UNDERLINE = 147,
  DIK_KANJI = 148,
  DIK_STOP = 149,
  DIK_AX = 150,
  DIK_UNLABELED = 151,
  DIK_NUMPADENTER = 156,
  DIK_RCONTROL = 157,
  DIK_NUMPADCOMMA = 179,
  DIK_DIVIDE = 181,
  DIK_SYSRQ = 183,
  DIK_RMENU = 184,
  DIK_PAUSE = 197,
  DIK_HOME = 199,
  DIK_UP = 200,
  DIK_PRIOR = 201,
  DIK_LEFT = 203,
  DIK_RIGHT = 205,
  DIK_END = 207,
  DIK_DOWN = 208,
  DIK_NEXT = 209,
  DIK_INSERT = 210,
  DIK_DELETE = 211,
  DIK_LWIN = 219,
  DIK_RWIN = 220,
  DIK_APPS = 221,
  DIK_POWER = 222,
  DIK_SLEEP = 223
} DIRECT_INPUT_KEYCODE;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef enum MUGEN_GAMETYPE_ {
  GAMETYPE_VS = 0,
  GAMETYPE_M = 1
} MUGEN_GAMETYPE;
typedef enum MUGEN_TRANS_TYPE_ {
  TRANS_DEFAULT = -1,
  TRANS_NONE = 0,
  TRANS_ADD = 1,
  TRANS_SUB = 2,
  TRANS_ALPHA = 3,
} MUGEN_TRANS_TYPE;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef enum MUGEN_EVAL_TYPE_ {
  EVAL_TYPE_INT = 0,
  EVAL_TYPE_FLOAT = 1,
  EVAL_TYPE_OPERATOR = 2,
  EVAL_TYPE_TRIGGER = 3,
  EVAL_TYPE_ERROR = 4
} MUGEN_EVAL_TYPE;
typedef enum MUGEN_EVAL_COMPARATOR_ {
  EVAL_EQ = 0,
  EVAL_NEQ = 1,
  EVAL_GT = 2,
  EVAL_GTE = 3,
  EVAL_LT = 4,
  EVAL_LTE = 5,
  EVAL_RANGE_IN_IN = 10,
  EVAL_RANGE_IN_OUT = 11,
  EVAL_RANGE_OUT_IN = 12,
  EVAL_RANGE_OUT_OUT = 13
} MUGEN_EVAL_COMPARATOR;
typedef enum MUGEN_EVAL_OPERATOR_ {
  EVAL_OP_EQ = 1,
  EVAL_OP_NEQ = 2,
  EVAL_OP_GT = 3,
  EVAL_OP_LT = 4,
  EVAL_OP_GTE = 5,
  EVAL_OP_LTE = 6,
  EVAL_OP_RANGE_OUT_OUT = 7,
  EVAL_OP_RANGE_IN_OUT = 8,
  EVAL_OP_RANGE_OUT_IN = 9,
  EVAL_OP_RANGE_IN_IN = 10,
  EVAL_OP_LAND = 11,
  EVAL_OP_LOR = 12,
  EVAL_OP_LNOT = 13,
  EVAL_OP_LXOR = 14,
  EVAL_OP_POW = 15,
  EVAL_OP_BAND = 16,
  EVAL_OP_BOR = 17,
  EVAL_OP_BXOR = 18,
  EVAL_OP_NEG = 19,
  EVAL_OP_IASSIGN = 20,
  EVAL_OP_FASSIGN = 21,
  EVAL_OP_BNOT = 22,
  EVAL_OP_ADD = 23,
  EVAL_OP_SUB = 24,
  EVAL_OP_MUL = 25,
  EVAL_OP_DIV = 26,
  EVAL_OP_MOD = 27,
  EVAL_OP_UNKNOWN1 = 28,
  EVAL_OP_UNKNOWN2 = 29
} MUGEN_EVAL_OPERATOR;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef enum MUGEN_PLAYER_PROJCONTACT_TYPE_ {
  PROJCONTACT_NONE = 0,
  PROJCONTACT_GUARDED = 1,
  PROJCONTACT_HIT = 2,
  PROJCONTACT_CANCEL = 3
} MUGEN_PLAYER_PROJCONTACT_TYPE;
typedef enum MUGEN_PLAYER_MOVECONTACT_TYPE_ {
  MOVECONTACT_NONE = 0,
  MOVECONTACT_GUARDED = 1,
  MOVECONTACT_HIT = 2,
  MOVECONTACT_REVERSED = 4
} MUGEN_PLAYER_MOVECONTACT_TYPE;
typedef enum MUGEN_PLAYER_STATETYPE_ {
  STATETYPE_S = 1,
  STATETYPE_C = 2,
  STATETYPE_A = 3,
  STATETYPE_L = 4,
  STATETYPE_U = 0xFFFFFFFF
} MUGEN_PLAYER_STATETYPE;
typedef enum MUGEN_PLAYER_MOVETYPE_ {
  MOVETYPE_I = 0,
  MOVETYPE_A = 1,
  MOVETYPE_H = 2,
  MOVETYPE_U = 0xFFFFFFFF
} MUGEN_PLAYER_MOVETYPE;
typedef enum MUGEN_PLAYER_PHYSICS_ {
  PHYSICS_N = 0,
  PHYSICS_S = 1,
  PHYSICS_C = 2,
  PHYSICS_A = 3,
  PHYSICS_U = 0xFFFFFFFF
} MUGEN_PLAYER_PHYSICS;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef enum MUGEN_SC_ID_ {
  ID_SC_Null = 0,
  ID_SC_ChangeState = 1,
  ID_SC_SelfState = 2,
  ID_SC_Turn = 3,
  ID_SC_VarSet = 4,
  ID_SC_VarAdd = 5,
  ID_SC_VarRandom = 6,
  ID_SC_VarRangeSet = 7,
  ID_SC_LifeSet = 10,
  ID_SC_LifeAdd = 11,
  ID_SC_PowerSet = 12,
  ID_SC_PowerAdd = 13,
  ID_SC_CtrlSet = 20,
  ID_SC_PosSet = 21,
  ID_SC_PosAdd = 22,
  ID_SC_PosFreeze = 23,
  ID_SC_VelSet = 24,
  ID_SC_VelAdd = 25,
  ID_SC_VelMul = 26,
  ID_SC_Gravity = 27,
  ID_SC_Offset = 28,
  ID_SC_HitBy = 30,
  ID_SC_NotHitBy = 30,
  ID_SC_ChangeAnim = 32,
  ID_SC_ChangeAnim2 = 33,
  ID_SC_PlaySnd = 34,
  ID_SC_StopSnd = 35,
  ID_SC_SndPan = 36,
  ID_SC_HitDef = 37,
  ID_SC_ReversalDef = 38,
  ID_SC_Projectile = 39,
  ID_SC_Width = 40,
  ID_SC_ScreenBound = 50,
  ID_SC_SprPriority = 51,
  ID_SC_AngleDraw = 60,
  ID_SC_AngleSet = 61,
  ID_SC_AngleAdd = 62,
  ID_SC_AngleMul = 63,
  ID_SC_Trans = 65,
  ID_SC_TargetBind = 70,
  ID_SC_BindToTarget = 71,
  ID_SC_TargetState = 72,
  ID_SC_TargetPowerAdd = 73,
  ID_SC_TargetLifeAdd = 74,
  ID_SC_TargetVelSet = 75,
  ID_SC_TargetVelAdd = 76,
  ID_SC_TargetFacing = 77,
  ID_SC_TargetDrop = 78,
  ID_SC_AttackDist = 90,
  ID_SC_PlayerPush = 91,
  ID_SC_HitFallSet = 100,
  ID_SC_HitVelSet = 101,
  ID_SC_HitFallDamage = 102,
  ID_SC_HitFallVel = 103,
  ID_SC_HitAdd = 104,
  ID_SC_AttackMulSet = 105,
  ID_SC_DefenceMulSet = 106,
  ID_SC_StateTypeSet = 110,
  ID_SC_HitOverride = 120,
  ID_SC_MoveHitReset = 130,
  ID_SC_AssertSpecial = 150,
  ID_SC_EnvShake = 200,
  ID_SC_FallEnvShake = 201,
  ID_SC_EnvColor = 202,
  ID_SC_GameMakeAnim = 203,
  ID_SC_AfterImage = 210,
  ID_SC_AfterImageTime = 211,
  ID_SC_Pause = 212,
  ID_SC_SuperPause = 214,
  ID_SC_MakeDust = 215,
  ID_SC_AllPalFx = 216,
  ID_SC_BGPalFx = 216,
  ID_SC_PalFx = 216,
  ID_SC_Explod = 220,
  ID_SC_RemoveExplod = 221,
  ID_SC_ExplodBindTime = 222,
  ID_SC_ModifyExplod = 223,
  ID_SC_Helper = 300,
  ID_SC_DestroySelf = 301,
  ID_SC_ParentVarSet = 304,
  ID_SC_ParentVarAdd = 305,
  ID_SC_DisplayToClipboard = 310,
  ID_SC_AppendToClipboard = 311,
  ID_SC_ClearClipboard = 312,
  ID_SC_BindToParent = 320,
  ID_SC_BindToRoot = 321,
  ID_SC_TagIn = 10051,
  ID_SC_TagOut = 10052
} MUGEN_SC_ID;
typedef enum MUGEN_TRIG_ID_ {
  ID_TRIG_Time = 0,
  ID_TRIG_AnimTime = 1,
  ID_TRIG_AnimElem = 2,
  ID_TRIG_Anim = 3,
  ID_TRIG_Pos = 4,
  ID_TRIG_ScreenPos = 5,
  ID_TRIG_Vel = 6,
  ID_TRIG_TimeMod = 7,
  ID_TRIG_P2Dist = 8,
  ID_TRIG_P2BodyDist = 9,
  ID_TRIG_P2Life = 10,
  ID_TRIG_FrondEdgeDist = 11,
  ID_TRIG_FrontEdgeBodyDist = 11,
  ID_TRIG_BackEdgeBodyDist = 12,
  ID_TRIG_BackEdgeDist = 12,
  ID_TRIG_Life = 15,
  ID_TRIG_LifeMax = 16,
  ID_TRIG_Power = 17,
  ID_TRIG_PowerMax = 18,
  ID_TRIG_Alive = 19,
  ID_TRIG_Command = 20,
  ID_TRIG_HitCount = 30,
  ID_TRIG_UniqHitCount = 31,
  ID_TRIG_MoveHit = 32,
  ID_TRIG_MoveGuarded = 33,
  ID_TRIG_MoveContact = 34,
  ID_TRIG_MoveReversed = 35,
  ID_TRIG_InGuardDist = 36,
  ID_TRIG_StateNo = 40,
  ID_TRIG_PrevStateNo = 41,
  ID_TRIG_P2StateNo = 42,
  ID_TRIG_StateType = 43,
  ID_TRIG_P2StateType = 44,
  ID_TRIG_MoveType = 45,
  ID_TRIG_P2MoveType = 46,
  ID_TRIG_Ctrl = 47,
  ID_TRIG_HitDefAttr = 48,
  ID_TRIG_Random = 51,
  ID_TRIG_NumProj = 60,
  ID_TRIG_ProjHit = 62,
  ID_TRIG_ProjGuarded = 63,
  ID_TRIG_ProjContact = 64,
  ID_TRIG_Name = 90,
  ID_TRIG_P1Name = 90,
  ID_TRIG_P2Name = 91,
  ID_TRIG_P3Name = 92,
  ID_TRIG_P4Name = 93,
  ID_TRIG_AuthorName = 94,
  ID_TRIG_NumPartner = 95,
  ID_TRIG_NumEnemy = 96,
  ID_TRIG_ID = 97,
  ID_TRIG_Facing = 99,
  ID_TRIG_HitFall = 100,
  ID_TRIG_HitShakeOver = 101,
  ID_TRIG_HitOver = 102,
  ID_TRIG_HitVel = 103,
  ID_TRIG_HitPauseTime = 104,
  ID_TRIG_CanRecover = 105,
  ID_TRIG_PalNo = 107,
  ID_TRIG_WinPerfect = 108,
  ID_TRIG_Win = 109,
  ID_TRIG_Lose = 110,
  ID_TRIG_DrawGame = 111,
  ID_TRIG_MatchOver = 112,
  ID_TRIG_GameTime = 113,
  ID_TRIG_RoundNo = 114,
  ID_TRIG_RoundState = 115,
  ID_TRIG_MatchNo = 116,
  ID_TRIG_RoundsExisted = 117,
  ID_TRIG_TeamSide = 120,
  ID_TRIG_TeamMode = 121,
  ID_TRIG_IsHomeTeam = 122,
  ID_TRIG_NumExplod = 150,
  ID_TRIG_NumTarget = 160,
  ID_TRIG_GetHitVar = 180,
  ID_TRIG_Const = 181,
  ID_TRIG_TicksPerSecond = 190,
  ID_TRIG_IsHelper = 201,
  ID_TRIG_NumHelper = 202,
  ID_TRIG_ParentDist = 203,
  ID_TRIG_RootDist = 204,
  ID_TRIG_StandBy = 205,
  ID_TRIG_Pi = 300,
  ID_TRIG_E = 301,
  ID_TRIG_IfElse = 305,
  ID_TRIG_Log = 310,
  ID_TRIG_Sin = 320,
  ID_TRIG_Cos = 321,
  ID_TRIG_Tan = 322,
  ID_TRIG_ASin = 323,
  ID_TRIG_ACos = 324,
  ID_TRIG_ATan = 325,
  ID_TRIG_Exp = 326,
  ID_TRIG_Ln = 327,
  ID_TRIG_Abs = 328,
  ID_TRIG_Floor = 329,
  ID_TRIG_Ceil = 330,
  ID_TRIG_AnimElemTime = 331,
  ID_TRIG_AnimExist = 332,
  ID_TRIG_SelfAnimExist = 333,
  ID_TRIG_PlayerIDExist = 334,
  ID_TRIG_IsHelper_ID = 335,
  ID_TRIG_NumHelper_ID = 336,
  ID_TRIG_ProjHitTime = 337,
  ID_TRIG_ProjGuardedTime = 338,
  ID_TRIG_ProjContactTime = 339,
  ID_TRIG_NumProjID = 340,
  ID_TRIG_NumExplod_ID = 341,
  ID_TRIG_NumTarget_ID = 342,
  ID_TRIG_Var = 343,
  ID_TRIG_FVar = 344,
  ID_TRIG_SysVar = 345,
  ID_TRIG_SysFVar = 346,
  ID_TRIG_ProjCancelTime = 347,
  ID_TRIG_AnimElemNo = 348
} MUGEN_TRIG_ID;
typedef enum MUGEN_REDIRECT_ID_ {
  ID_RD_None = 0,
  ID_RD_Parent = 1,
  ID_RD_Root = 2,
  ID_RD_Helper = 3,
  ID_RD_Target = 4,
  ID_RD_Partner = 5,
  ID_RD_Enemy = 6,
  ID_RD_EnemyNear = 7,
  ID_RD_PlayerID = 8
} MUGEN_REDIRECT_ID;
typedef enum MUGEN_GET_HIT_VAR_ID_ {
  ID_GHV_XVelAdd = 0,
  ID_GHV_YVelAdd,
  ID_GHV_Type,
  ID_GHV_AnimType,
  ID_GHV_AirType,
  ID_GHV_GroundType,
  ID_GHV_Damage,
  ID_GHV_HitCount,
  ID_GHV_FallCount,
  ID_GHV_HitShakeTime,
  ID_GHV_HitTime,
  ID_GHV_SlideTime,
  ID_GHV_CtrlTime,
  ID_GHV_RecoverTime,
  ID_GHV_XOff,
  ID_GHV_YOff,
  ID_GHV_ZOff,
  ID_GHV_XVel,
  ID_GHV_YVel,
  ID_GHV_YAccel,
  ID_GHV_ChainID,
  ID_GHV_Guarded,
  ID_GHV_IsBound,
  ID_GHV_Fall,
  ID_GHV_Fall_Damage,
  ID_GHV_Fall_XVel,
  ID_GHV_Fall_YVel,
  ID_GHV_Fall_Recover,
  ID_GHV_Fall_Time,
  ID_GHV_Fall_RecoverTime,
  ID_GHV_Fall_Kill,
  ID_GHV_Fall_EnvShake_Time,
  ID_GHV_Fall_EnvShake_Dir,
  ID_GHV_Fall_EnvShake_Ampl,
  ID_GHV_Fall_EnvShake_Freq,
  ID_GHV_Fall_EnvShake_Phase,
} MUGEN_GET_HIT_VAR_ID;
typedef enum MUGEN_ASSERT_SPECIAL_ID_ {
  ID_AS_Intro = 0,
  ID_AS_RoundNotOver = 1,
  ID_AS_NoKO = 2,
  ID_AS_NoKOSnd = 3,
  ID_AS_NoKOSlow = 4,
  ID_AS_NoMusic = 5,
  ID_AS_GlobalNoShadow = 6,
  ID_AS_TimerFreeze = 7,
  ID_AS_NoBarDisplay = 8,
  ID_AS_NoBG = 9,
  ID_AS_NoFG = 10,
  ID_AS_NoStandGuard = 16,
  ID_AS_NoCrouchGuard = 17,
  ID_AS_NoAirGuard = 18,
  ID_AS_NoAutoTurn = 19,
  ID_AS_NoShadow = 20,
  ID_AS_NoJuggleCheck = 21,
  ID_AS_NoWalk = 22,
  ID_AS_NoUnguardable = 23,
  ID_AS_Invisible = 24
} MUGEN_ASSERT_SPECIAL_ID;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct AL_BITMAP_ AL_BITMAP, *PAL_BITMAP;
typedef struct GFX_VTABLE_ GFX_VTABLE, *PGFX_VTABLE;
typedef struct RLE_SPRITE_ RLE_SPRITE, *PRLE_SPRITE;
typedef struct FONT_GLYPH_ FONT_GLYPH, *PFONT_GLYPH;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct SAMPLE_ SAMPLE, *PSAMPLE;

typedef struct CHANNEL_INFO_ CHANNEL_INFO, *PCHANNEL_INFO;
typedef struct ENVELOPE_INFO_ ENVELOPE_INFO, *PENVELOPE_INFO;

typedef struct JGMOD_ JGMOD, *PJGMOD;
typedef struct NOTE_INFO_ NOTE_INFO, *PNOTE_INFO;
typedef struct SAMPLE_INFO_ SAMPLE_INFO, *PSAMPLE_INFO;
typedef struct INSTRUMENT_INFO_ INSTRUMENT_INFO, *PINSTRUMENT_INFO;
typedef struct PATTERN_INFO_ PATTERN_INFO, *PPATTERN_INFO;

typedef struct MODTYPE_ MODTYPE, *PMODTYPE;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct DIGI_DRIVER_ DIGI_DRIVER, *PDIGI_DRIVER;

typedef struct VOICEINFO_ VOICEINFO, *PVOICEINFO;

typedef struct MUSIC_INFO_ MUSIC_INFO, *PMUSIC_INFO;

typedef struct In_Module_ In_Module, *PIn_Module;
typedef struct Out_Module_ Out_Module, *POut_Module;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MIDI_ MIDI, *PMIDI;
typedef struct MIDI_TRACK_ MIDI_TRACK, *PMIDI_TRACK;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct KB_BUFFER_ KB_BUFFER, *PKB_BUFFER;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct PACKFILE_ PACKFILE, *PPACKFILE;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MUGEN_PLAYER_REDIRECTS MUGEN_PLAYER_REDIRECTS, *PMUGEN_PLAYER_REDIRECTS;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef union MUGEN_EVAL_NODE_ MUGEN_EVAL_NODE, *PMUGEN_EVAL_NODE;
typedef union MUGEN_EVAL_EXPR_VALUE_ MUGEN_EVAL_EXPR_VALUE, *PMUGEN_EVAL_EXPR_VALUE;
typedef struct MUGEN_EVAL_TRIGGER_ MUGEN_EVAL_TRIGGER, *PMUGEN_EVAL_TRIGGER;
typedef struct MUGEN_EVAL_VALUE_ MUGEN_EVAL_VALUE, *PMUGEN_EVAL_VALUE;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MUGEN_FONT_ MUGEN_FONT, *PMUGEN_FONT;
typedef struct MUGEN_SOUND_ MUGEN_SOUND, *PMUGEN_SOUND;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct ABSTRUCT_ARRAY_INFO_ ABSTRUCT_ARRAY_INFO, *PABSTRUCT_ARRAY_INFO;
typedef struct ABSTRUCT_ARRAY_LIST_ ABSTRUCT_ARRAY_LIST, *PABSTRUCT_ARRAY_LIST;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MUGEN_AFTERIMAGE_INFO_ MUGEN_AFTERIMAGE_INFO, *PMUGEN_AFTERIMAGE_INFO;
typedef struct MUGEN_AFTERIMAGE_DATA_ MUGEN_AFTERIMAGE_DATA, *PMUGEN_AFTERIMAGE_DATA;
typedef struct MUGEN_AFTERIMAGE_LIST_ MUGEN_AFTERIMAGE_LIST, *PMUGEN_AFTERIMAGE_LIST;
typedef struct MUGEN_AFTERIMAGE_PALLETES_ MUGEN_AFTERIMAGE_PALLETES, *PMUGEN_AFTERIMAGE_PALLETES;

typedef struct MUGEN_ANIM_USED_ MUGEN_ANIM_USED, *PMUGEN_ANIM_USED;
typedef struct MUGEN_ANIM_INFO_EX_ MUGEN_ANIM_INFO_EX, *PMUGEN_ANIM_INFO_EX;
typedef struct MUGEN_ANIM_INFO_ MUGEN_ANIM_INFO, *PMUGEN_ANIM_INFO;
typedef struct MUGEN_ANIM_DATA_ MUGEN_ANIM_DATA, *PMUGEN_ANIM_DATA;
typedef struct MUGEN_ANIM_LIST_ MUGEN_ANIM_LIST, *PMUGEN_ANIM_LIST;

typedef struct MUGEN_ANIM_ELEM_INFO_ MUGEN_ANIM_ELEM_INFO, *PMUGEN_ANIM_ELEM_INFO;
typedef struct MUGEN_ANIM_ELEM_DATA_ MUGEN_ANIM_ELEM_DATA, *PMUGEN_ANIM_ELEM_DATA;
typedef struct MUGEN_ANIM_ELEM_LIST_ MUGEN_ANIM_ELEM_LIST, *PMUGEN_ANIM_ELEM_LIST;

typedef struct MUGEN_CLSN_INFO_ MUGEN_CLSN_INFO, *PMUGEN_CLSN_INFO;
typedef struct MUGEN_CLSN_DATA_ MUGEN_CLSN_DATA, *PMUGEN_CLSN_DATA;

typedef struct MUGEN_SFF_INFO_EX_ MUGEN_SFF_INFO_EX, *PMUGEN_SFF_INFO_EX;
typedef struct MUGEN_SFF_INFO_ MUGEN_SFF_INFO, *PMUGEN_SFF_INFO;
typedef struct MUGEN_SFF_DATA_ MUGEN_SFF_DATA, *PMUGEN_SFF_DATA;
typedef struct MUGEN_SFF_LIST_ MUGEN_SFF_LIST, *PMUGEN_SFF_LIST;

typedef struct MUGEN_PALLETE_INFO_ MUGEN_PALLETE_INFO, *PMUGEN_PALLETE_INFO;
typedef struct MUGEN_PALLETE_DATA_ MUGEN_PALLETE_DATA, *PMUGEN_PALLETE_DATA;
typedef struct MUGEN_PALLETE_LIST_ MUGEN_PALLETE_LIST, *PMUGEN_PALLETE_LIST;
typedef struct MUGEN_PALLETE_DATA_RGB_ MUGEN_PALLETE_DATA_RGB, *PMUGEN_PALLETE_DATA_RGB;
typedef struct MUGEN_PALLETE_PARAMS_ MUGEN_PALLETE_PARAMS, *PMUGEN_PALLETE_PARAMS;

typedef struct MUGEN_SND_INFO_ MUGEN_SND_INFO, *PMUGEN_SND_INFO;
typedef struct MUGEN_SND_DATA_ MUGEN_SND_DATA, *PMUGEN_SND_DATA;
typedef struct MUGEN_SND_LIST_ MUGEN_SND_LIST, *PMUGEN_SND_LIST;

typedef struct MUGEN_STATE_DEF_INFO_ MUGEN_STATE_DEF_INFO, *PMUGEN_STATE_DEF_INFO;
typedef struct MUGEN_STATE_DEF_DATA_ MUGEN_STATE_DEF_DATA, *PMUGEN_STATE_DEF_DATA;
typedef struct MUGEN_STATE_DEF_LIST_ MUGEN_STATE_DEF_LIST, *PMUGEN_STATE_DEF_LIST;

typedef struct MUGEN_SC_INFO_ MUGEN_SC_INFO, *PMUGEN_SC_INFO;
typedef struct MUGEN_SC_DATA_ MUGEN_SC_DATA, *PMUGEN_SC_DATA;
typedef struct MUGEN_SC_LIST_ MUGEN_SC_LIST, *PMUGEN_SC_LIST;
typedef union MUGEN_SC_PARAMS_EX_ MUGEN_SC_PARAMS_EX, *PMUGEN_SC_PARAMS_EX;
typedef struct MUGEN_SC_PARAMS_EX_HITOVERRIDE_ MUGEN_SC_PARAMS_EX_HITOVERRIDE, *PMUGEN_SC_PARAMS_EX_HITOVERRIDE;
typedef struct MUGEN_SC_PARAMS_EX_ENVSHAKE_ MUGEN_SC_PARAMS_EX_ENVSHAKE, *PMUGEN_SC_PARAMS_EX_ENVSHAKE;
typedef struct MUGEN_SC_PARAMS_EX_AFTERIMAGE_ MUGEN_SC_PARAMS_EX_AFTERIMAGE, *PMUGEN_SC_PARAMS_EX_AFTERIMAGE;
typedef struct MUGEN_SC_PARAMS_EX_PAUSE_ MUGEN_SC_PARAMS_EX_PAUSE, *PMUGEN_SC_PARAMS_EX_PAUSE;
typedef struct MUGEN_SC_PARAMS_EX_SUPERPAUSE_ MUGEN_SC_PARAMS_EX_SUPERPAUSE, *PMUGEN_SC_PARAMS_EX_SUPERPAUSE;
typedef struct MUGEN_SC_PARAMS_EX_PALFX_ MUGEN_SC_PARAMS_EX_PALFX, *PMUGEN_SC_PARAMS_EX_PALFX;
typedef struct MUGEN_SC_PARAMS_EX_EXPLOD_ MUGEN_SC_PARAMS_EX_EXPLOD, *PMUGEN_SC_PARAMS_EX_EXPLOD;
typedef struct MUGEN_SC_PARAMS_EX_HELPER_ MUGEN_SC_PARAMS_EX_HELPER, *PMUGEN_SC_PARAMS_EX_HELPER;
typedef struct MUGEN_SC_PARAMS_EX_CLIPBOARD_ MUGEN_SC_PARAMS_EX_CLIPBOARD, *PMUGEN_SC_PARAMS_EX_CLIPBOARD;
typedef struct MUGEN_SC_PARAMS_EX_PLAYSND_ MUGEN_SC_PARAMS_EX_PLAYSND, *PMUGEN_SC_PARAMS_EX_PLAYSND;
typedef struct MUGEN_SC_PARAMS_EX_HITDEF_ MUGEN_SC_PARAMS_EX_HITDEF, *PMUGEN_SC_PARAMS_EX_HITDEF;
typedef struct MUGEN_SC_PARAMS_EX_PROJECTILE_ MUGEN_SC_PARAMS_EX_PROJECTILE, *PMUGEN_SC_PARAMS_EX_PROJECTILE;

typedef struct MUGEN_TRIGGER_INFO_ MUGEN_TRIGGER_INFO, *PMUGEN_TRIGGER_INFO;
typedef struct MUGEN_TRIGGER_DATA_ MUGEN_TRIGGER_DATA, *PMUGEN_TRIGGER_DATA;
typedef struct MUGEN_TRIGGER_LIST_ MUGEN_TRIGGER_LIST, *PMUGEN_TRIGGER_LIST;

typedef struct MUGEN_TARGET_INFO_ MUGEN_TARGET_INFO, *PMUGEN_TARGET_INFO;
typedef struct MUGEN_TARGET_DATA_ MUGEN_TARGET_DATA, *PMUGEN_TARGET_DATA;
typedef struct MUGEN_TARGET_LIST_ MUGEN_TARGET_LIST, *PMUGEN_TARGET_LIST;

typedef struct MUGEN_PROJECTILE_INFO_EX_ MUGEN_PROJECTILE_INFO_EX, *PMUGEN_PROJECTILE_INFO_EX;
typedef struct MUGEN_PROJECTILE_INFO_ MUGEN_PROJECTILE_INFO, *PMUGEN_PROJECTILE_INFO;
typedef struct MUGEN_PROJECTILE_DATA_ MUGEN_PROJECTILE_DATA, *PMUGEN_PROJECTILE_DATA;
typedef struct MUGEN_PROJECTILE_LIST_ MUGEN_PROJECTILE_LIST, *PMUGEN_PROJECTILE_LIST;

typedef struct MUGEN_EXPLODS_INFO_ MUGEN_EXPLODS_INFO, *PMUGEN_EXPLODS_INFO;
typedef struct MUGEN_EXPLODS_DATA_ MUGEN_EXPLODS_DATA, *PMUGEN_EXPLODS_DATA;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MUGEN_SYSTEM_VIEW_ITEM_ MUGEN_SYSTEM_VIEW_ITEM, *PMUGEN_SYSTEM_VIEW_ITEM;
typedef union MUGEN_SYSTEM_VIEW_COMPONENT_ MUGEN_SYSTEM_VIEW_COMPONENT, *PMUGEN_SYSTEM_VIEW_COMPONENT;
typedef struct MUGEN_SYSTEM_ANIM_ MUGEN_SYSTEM_ANIM, *PMUGEN_SYSTEM_ANIM;
typedef struct MUGEN_SYSTEM_SPRITE_ MUGEN_SYSTEM_SPRITE, *PMUGEN_SYSTEM_SPRITE;
typedef struct MUGEN_SYSTEM_TEXT_ MUGEN_SYSTEM_TEXT, *PMUGEN_SYSTEM_TEXT;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MUGEN_CONFIG_OPTIONS_ MUGEN_CONFIG_OPTIONS, *PMUGEN_CONFIG_OPTIONS;
typedef struct MUGEN_CONFIG_RULES_ MUGEN_CONFIG_RULES, *PMUGEN_CONFIG_RULES;
typedef struct MUGEN_CONFIG_CONFIG_ MUGEN_CONFIG_CONFIG, *PMUGEN_CONFIG_CONFIG;
typedef struct MUGEN_CONFIG_VIDEO_WIN_ MUGEN_CONFIG_VIDEO_WIN, *PMUGEN_CONFIG_VIDEO_WIN;
typedef struct MUGEN_CONFIG_SOUND_WIN_ MUGEN_CONFIG_SOUND_WIN, *PMUGEN_CONFIG_SOUND_WIN;
typedef struct MUGEN_CONFIG_SOUND_WIN2_ MUGEN_CONFIG_SOUND_WIN2, *PMUGEN_CONFIG_SOUND_WIN2;
typedef struct MUGEN_CONFIG_MISC_ MUGEN_CONFIG_MISC, *PMUGEN_CONFIG_MISC;
typedef struct MUGEN_CONFIG_ARCADE_ MUGEN_CONFIG_ARCADE, *PMUGEN_CONFIG_ARCADE;
typedef struct MUGEN_CONFIG_INPUT_ MUGEN_CONFIG_INPUT, *PMUGEN_CONFIG_INPUT;
typedef struct MUGEN_CONFIG_KEYS_ MUGEN_CONFIG_KEYS, *PMUGEN_CONFIG_KEYS;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MUGEN_FIGHT_LIFEBAR_ MUGEN_FIGHT_LIFEBAR, *PMUGEN_FIGHT_LIFEBAR;
typedef struct MUGEN_FIGHT_SIMUL_LIFEBAR_ MUGEN_FIGHT_SIMUL_LIFEBAR, *PMUGEN_FIGHT_SIMUL_LIFEBAR;
#define MUGEN_FIGHT_TURNS_LIFEBAR MUGEN_FIGHT_SIMUL_LIFEBAR
typedef struct MUGEN_FIGHT_POWERBAR_ MUGEN_FIGHT_POWERBAR, *PMUGEN_FIGHT_POWERBAR;
typedef struct MUGEN_FIGHT_FACE_ MUGEN_FIGHT_FACE, *PMUGEN_FIGHT_FACE;
typedef struct MUGEN_FIGHT_SIMUL_FACE_ MUGEN_FIGHT_SIMUL_FACE, *PMUGEN_FIGHT_SIMUL_FACE;
typedef struct MUGEN_FIGHT_TURNS_FACE_ MUGEN_FIGHT_TURNS_FACE, *PMUGEN_FIGHT_TURNS_FACE;
typedef struct MUGEN_FIGHT_NAME_ MUGEN_FIGHT_NAME, *PMUGEN_FIGHT_NAME;
typedef struct MUGEN_FIGHT_SIMUL_NAME_ MUGEN_FIGHT_SIMUL_NAME, *PMUGEN_FIGHT_SIMUL_NAME;
#define MUGEN_FIGHT_TURNS_NAME MUGEN_FIGHT_SIMUL_NAME
typedef struct MUGEN_FIGHT_TIME_ MUGEN_FIGHT_TIME, *PMUGEN_FIGHT_TIME;
typedef struct MUGEN_FIGHT_COMBO_ MUGEN_FIGHT_COMBO, *PMUGEN_FIGHT_COMBO;
typedef struct MUGEN_FIGHT_ROUND_ MUGEN_FIGHT_ROUND, *PMUGEN_FIGHT_ROUND;
typedef struct MUGEN_FIGHT_WINICON_ MUGEN_FIGHT_WINICON, *PMUGEN_FIGHT_WINICON;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MUGEN_SYSTEM_TITLE_INFO_ MUGEN_SYSTEM_TITLE_INFO, *PMUGEN_SYSTEM_TITLE_INFO;
typedef struct MUGEN_SYSTEM_SELECTINFO_ MUGEN_SYSTEM_SELECTINFO, *PMUGEN_SYSTEM_SELECTINFO;
typedef struct MUGEN_SYSTEM_SELECTINFO2_ MUGEN_SYSTEM_SELECTINFO2, *PMUGEN_SYSTEM_SELECTINFO2;
typedef struct MUGEN_SYSTEM_VS_SCREEN_ MUGEN_SYSTEM_VS_SCREEN, *PMUGEN_SYSTEM_VS_SCREEN;
typedef struct MUGEN_SYSTEM_DEMO_MODE_ MUGEN_SYSTEM_DEMO_MODE, *PMUGEN_SYSTEM_DEMO_MODE;
typedef struct MUGEN_SYSTEM_CONTINUE_SCREEN_ MUGEN_SYSTEM_CONTINUE_SCREEN, *PMUGEN_SYSTEM_CONTINUE_SCREEN;
typedef struct MUGEN_SYSTEM_GAME_OVER_SCREEN_ MUGEN_SYSTEM_GAME_OVER_SCREEN, *PMUGEN_SYSTEM_GAME_OVER_SCREEN;
typedef struct MUGEN_SYSTEM_WINSCREEN_ MUGEN_SYSTEM_WINSCREEN, *PMUGEN_SYSTEM_WINSCREEN;
typedef struct MUGEN_SYSTEM_DEFAULT_ENDING_ MUGEN_SYSTEM_DEFAULT_ENDING, *PMUGEN_SYSTEM_DEFAULT_ENDING;
typedef struct MUGEN_SYSTEM_END_CREDITS_ MUGEN_SYSTEM_END_CREDITS, *PMUGEN_SYSTEM_END_CREDITS;
typedef struct MUGEN_SYSTEM_SURVIVAL_RESULTS_SCREEN_ MUGEN_SYSTEM_SURVIVAL_RESULTS_SCREEN, *PMUGEN_SYSTEM_SURVIVAL_RESULTS_SCREEN;
typedef struct MUGEN_SYSTEM_OPTION_INFO_ MUGEN_SYSTEM_OPTION_INFO, *PMUGEN_SYSTEM_OPTION_INFO;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MUGEN_STAGE_CAMERA_ MUGEN_STAGE_CAMERA, *PMUGEN_STAGE_CAMERA;
typedef struct MUGEN_STAGE_PLAYERINFO_ MUGEN_STAGE_PLAYERINFO, *PMUGEN_STAGE_PLAYERINFO;
typedef struct MUGEN_STAGE_SCALING_ MUGEN_STAGE_SCALING, *PMUGEN_STAGE_SCALING;
typedef struct MUGEN_STAGE_BOUND_ MUGEN_STAGE_BOUND, *PMUGEN_STAGE_BOUND;
typedef struct MUGEN_STAGE_SHADOW_ MUGEN_STAGE_SHADOW, *PMUGEN_STAGE_SHADOW;
typedef struct MUGEN_STAGE_REFLECTION_ MUGEN_STAGE_REFLECTION, *PMUGEN_STAGE_REFLECTION;
typedef struct MUGEN_STAGE_MUSIC_ MUGEN_STAGE_MUSIC, *PMUGEN_STAGE_MUSIC;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MUGEN_GAME_VAR_ MUGEN_GAME_VAR, *PMUGEN_GAME_VAR;

typedef struct MUGEN_VERSION_DATA_ MUGEN_VERSION_DATA, *PMUGEN_VERSION_DATA;
typedef struct MUGEN_REGISTERED_CHARS_ MUGEN_REGISTERED_CHARS, *PMUGEN_REGISTERED_CHARS;
typedef struct MUGEN_SELECT_OPTION_ MUGEN_SELECT_OPTION, *PMUGEN_SELECT_OPTION;
typedef struct MUGEN_REGISTERED_PORTRAITS_ MUGEN_REGISTERED_PORTRAITS, *PMUGEN_REGISTERED_PORTRAITS;
typedef struct MUGEN_STAGE_LIST_ MUGEN_STAGE_LIST, *PMUGEN_STAGE_LIST;
typedef struct MUGEN_TURN_CHARSET_ MUGEN_TURN_CHARSET, *PMUGEN_TURN_CHARSET;
typedef struct MUGEN_PAL_FX_ MUGEN_PAL_FX, *PMUGEN_PAL_FX;
typedef struct MUGEN_ENV_SHAKE_ MUGEN_ENV_SHAKE, *PMUGEN_ENV_SHAKE;
typedef struct MUGEN_ASSERT_SPECIAL_FLAGS_ MUGEN_ASSERT_SPECIAL_FLAGS, *PMUGEN_ASSERT_SPECIAL_FLAGS;
typedef struct MUGEN_INT_CIRC_BUF_ MUGEN_INT_CIRC_BUF, *PMUGEN_INT_CIRC_BUF;
typedef struct MUGEN_SC_PAUSE_ MUGEN_SC_PAUSE, *PMUGEN_SC_PAUSE;
typedef struct MUGEN_PAL_GROUP_ MUGEN_PAL_GROUP, *PMUGEN_PAL_GROUP;
typedef struct MUGEN_COMBO_CNT_ MUGEN_COMBO_CNT, *PMUGEN_COMBO_CNT;
typedef struct MUGEN_CLIPBOARD_ MUGEN_CLIPBOARD, *PMUGEN_CLIPBOARD;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

typedef struct MUGEN_PLAYER_ MUGEN_PLAYER, *PMUGEN_PLAYER;

typedef struct MUGEN_PLAYER_INFO_ MUGEN_PLAYER_INFO, *PMUGEN_PLAYER_INFO;
typedef struct MUGEN_PLAYER_CONSTRAINTS_ MUGEN_PLAYER_CONSTRAINTS, *PMUGEN_PLAYER_CONSTRAINTS;
typedef struct MUGEN_PLAYER_ASSERTSPECIAL_FLAGS_ MUGEN_PLAYER_ASSERTSPECIAL_FLAGS, *PMUGEN_PLAYER_ASSERTSPECIAL_FLAGS;
typedef struct MUGEN_KEY_INPUTS_ MUGEN_KEY_INPUTS, *PMUGEN_KEY_INPUTS;
typedef struct MUGEN_COMMAND_TIMES_ MUGEN_COMMAND_TIMES, *PMUGEN_COMMAND_TIMES;
typedef struct MUGEN_GET_HIT_VARS_ MUGEN_GET_HIT_VARS, *PMUGEN_GET_HIT_VARS;
typedef struct MUGEN_HIT_OVERRIDE_ MUGEN_HIT_OVERRIDE, *PMUGEN_HIT_OVERRIDE;
typedef struct MUGEN_HIT_DEF_PARAMS_ MUGEN_HIT_DEF_PARAMS, *PMUGEN_HIT_DEF_PARAMS;
typedef struct MUGEN_PLAYER_AI_ MUGEN_PLAYER_AI, *PMUGEN_PLAYER_AI;
typedef struct MUGEN_PLAYER_AI_PLAYERS_STATE_ MUGEN_PLAYER_AI_PLAYERS_STATE, *PMUGEN_PLAYER_AI_PLAYERS_STATE;
typedef struct MUGEN_PLAYER_AI_PARAMS_ MUGEN_PLAYER_AI_PARAMS, *PMUGEN_PLAYER_AI_PARAMS;
typedef struct MUGEN_PLAYER_BIND_ MUGEN_PLAYER_BIND, *PMUGEN_PLAYER_BIND;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct AL_BITMAP_ {
  int32_t w;
  int32_t h;
  int32_t clip;
  int32_t cl;
  int32_t cr;
  int32_t ct;
  int32_t cb;
  GFX_VTABLE* vtable;
  void* write_bank;
  void* read_bank;
  void* dat;
  uint32_t id;
  void* extra;
  int32_t x_ofs;
  int32_t y_ofs;
  int32_t seg;
  uint8_t* line[];
};
struct GFX_VTABLE_ {
  int32_t color_depth;
  int32_t mask_color;
  void* unwrite_bank;
  void (*pSet_Clip)(AL_BITMAP*);
  void (*pAcquire)(AL_BITMAP*);
  void (*pRelease)(AL_BITMAP*);
  AL_BITMAP* (*pCreate_Sub_Bitmap)(AL_BITMAP*, int32_t, int32_t, int32_t, int32_t);
  void (*pCreated_Sub_Bitmap)(AL_BITMAP*, AL_BITMAP*);
  int32_t (*pGetPixel)(AL_BITMAP*, int32_t, int32_t);
  void (*pPutPixel)(AL_BITMAP*, int32_t, int32_t, int32_t);
  void (*pVLine)(AL_BITMAP*, int32_t, int32_t, int32_t, int32_t);
  void (*pHLine)(AL_BITMAP*, int32_t, int32_t, int32_t, int32_t);
  void (*pHFill)(AL_BITMAP*, int32_t, int32_t, int32_t, int32_t);
  void (*pLine)(AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pRectFill)(AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t);
  int32_t (*pTriangle)(AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pDraw_Sprite)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t);
  void (*pDraw_256_Sprite)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t);
  void (*pDraw_Sprite_V_Flip)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t);
  void (*pDraw_Sprite_H_Flip)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t);
  void (*pDraw_Sprite_VH_Flip)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t);
  void (*pDraw_Trans_Sprite)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t);
  void (*pDraw_Trans_RGBA_Sprite)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t);
  void (*pDraw_Lit_Sprite)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t);
  void (*pDraw_RLE_Sprite)(AL_BITMAP*, RLE_SPRITE*, int32_t, int32_t);
  void (*pDraw_Trans_RLE_Sprite)(AL_BITMAP*, RLE_SPRITE*, int32_t, int32_t);
  void (*pDraw_Trans_RGBA_RLE_Sprite)(AL_BITMAP*, RLE_SPRITE*, int32_t, int32_t);
  void (*pDraw_Lit_RLE_Sprite)(AL_BITMAP*, RLE_SPRITE*, int32_t, int32_t, int32_t);
  void (*pDraw_Character)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t);
  void (*pDraw_Glyph)(AL_BITMAP*, FONT_GLYPH*, int32_t, int32_t, int32_t);
  void (*pBlit_From_Memory)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pBlit_To_Memory)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pBlit_From_System)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pBlit_To_System)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pBlit_To_Self)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pBlit_To_Self_Forward)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pBlit_To_Self_Backward)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pBlit_Between_Formats)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pMasked_Blit)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pClear_To_Color)(AL_BITMAP*, int32_t);
  void (*pPivot_Scaled_Sprite_Flip)(AL_BITMAP*, AL_BITMAP*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*pDraw_Sprite_End)(void);
  void (*pBlit_End)(void);
};
struct RLE_SPRITE_ {
  int32_t w;
  int32_t h;
  int32_t color_depth;
  int32_t size;
  char dat[];
};
struct FONT_GLYPH_ {
  int16_t w;
  int16_t h;
  uint8_t dat[];
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct SAMPLE_ {
  int32_t bits;
  int32_t stereo; /* -1: stereo, 0: mono */
  int32_t freq;
  int32_t priority;
  uint32_t len;
  uint32_t loop_start;
  uint32_t loop_end;
  uint32_t param;
  void* data; /* PCM */
};

struct ENVELOPE_INFO_ {
  int32_t env[12];
  int32_t pos[12];
  int32_t flg;
  int32_t pts;
  int32_t loopbeg;
  int32_t loopend;
  int32_t susbeg;
  int32_t susend;
  int32_t a;
  int32_t b;
  int32_t p;
  int32_t v;
};
struct CHANNEL_INFO_ {
  ENVELOPE_INFO volenv;
  ENVELOPE_INFO panenv;
  int32_t instrument;
  int32_t sample;
  int32_t volume;
  int32_t note;
  int32_t period;
  int32_t c2spd;
  int32_t transpose;
  int32_t pan;
  int32_t kick;
  int32_t keyon;
  int32_t volfade;
  int32_t instfade;
  int32_t temp_volume;
  int32_t temp_period;
  int32_t temp_pan;
  int32_t pan_slide_common;
  int32_t pan_slide;
  int32_t pan_slide_left;
  int32_t pan_slide_right;
  int32_t pro_pitch_slide_on;
  int32_t pro_pitch_slide;
  int32_t pro_fine_pitch_slide;
  int32_t s3m_pitch_slide_on;
  int32_t s3m_pitch_slide;
  int32_t s3m_fine_pitch_slide;
  int32_t xm_pitch_slide_up_on;
  int32_t xm_pitch_slide_up;
  int32_t xm_pitch_slide_down_on;
  int32_t xm_pitch_slide_down;
  int32_t xm_fine_pitch_slide_up;
  int32_t xm_fine_pitch_silde_down;
  int32_t xm_extra_fine_pitch_slide_up;
  int32_t xm_x_up;
  int32_t xm_x_down;
  int32_t pro_volume_slide;
  int32_t s3m_volume_slide_on;
  int32_t s3m_fine_volume_slide;
  int32_t s3m_volume_slide;
  int32_t xm_volume_slide_on;
  int32_t xm_volume_slide;
  int32_t xm_fine_volume_slide_up;
  int32_t xm_fine_volume_slide_down;
  int32_t loop_on;
  int32_t loop_times;
  int32_t loop_start;
  int32_t tremolo_on;
  int32_t tremolo_waveform;
  char tremolo_pointer;
  int32_t tremolo_speed;
  int32_t tremolo_depth;
  int32_t tremolo_shift;
  int32_t vibrato_on;
  int32_t vibrato_waveform;
  char vibrato_pointer;
  int32_t vibrato_speed;
  int32_t vibrato_depth;
  int32_t vibrato_shift;
  int32_t slide2period_on;
  int32_t slide2period_spd;
  int32_t slide2period;
  int32_t arpeggio_on;
  int32_t arpeggio;
  int32_t tremor_on;
  int32_t tremor_count;
  int32_t tremor_set;
  int32_t delay_sample;
  int32_t cut_sample;
  int32_t glissando;
  int32_t retrig;
  int32_t s3m_retrig_on;
  int32_t s3m_retrig;
  int32_t s3m_retrig_slide;
  int32_t sample_offset_on;
  int32_t sample_offset;
  int32_t global_volume_slide_on;
  int32_t global_volume_slide;
};

struct JGMOD_ {
  char name[29];
  SAMPLE_INFO* si;
  PATTERN_INFO* pi;
  INSTRUMENT_INFO* ii;
  SAMPLE* s;
  int32_t no_trk;
  int32_t no_pat;
  int32_t pat_table[256];
  int32_t panning[64];
  int32_t flag;
  int32_t tempo;
  int32_t bpm;
  int32_t restart_pos;
  int32_t no_chn;
  int32_t no_instrument;
  int32_t no_sample;
  int32_t global_volume;
};
struct NOTE_INFO_ {
  int32_t sample;
  int32_t note;
  int32_t volume;
  int32_t command;
  int32_t extcommand;
};
struct SAMPLE_INFO_ {
  int32_t lenght;
  int32_t c2spd;
  int32_t transpose;
  int32_t volume;
  int32_t pan;
  int32_t repoff;
  int32_t replen;
  int32_t loop;
  int32_t vibrato_type;
  int32_t vibrato_spd;
  int32_t vibrato_depth;
  int32_t vibrato_rate;
};
struct INSTRUMENT_INFO_ {
  int32_t sample_number[96];
  int32_t volenv[12];
  int32_t volpos[12];
  int32_t no_volenv;
  int32_t vol_type;
  int32_t vol_susbeg;
  int32_t vol_susend;
  int32_t vol_begin;
  int32_t vol_end;
  int32_t panenv[12];
  int32_t panpos[12];
  int32_t no_panenv;
  int32_t pan_type;
  int32_t pan_susbeg;
  int32_t pan_susend;
  int32_t pan_begin;
  int32_t pan_end;
  int32_t volume_fadeout;
};
struct PATTERN_INFO_ {
  NOTE_INFO* ni;
  int32_t no_pos;
};

struct MODTYPE_ {
  char id[5];
  char no_channel;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct DIGI_DRIVER_ {
  int32_t id;
  char* name;
  char* desc;
  char* ascii_name;
  int32_t voices;
  int32_t basevoice;
  int32_t max_voices;
  int32_t def_voices;
  int32_t (*detect)(int32_t);
  int32_t (*init)(int32_t, int32_t);
  void (*exit)(int32_t);
  int32_t (*mixer_volume)(int32_t);
  void* (*lock_voice)(int32_t, int32_t, int32_t);
  void (*unlock_voice)(int32_t);
  int32_t (*buffer_size)(void);
  void (*init_voice)(int32_t, SAMPLE*);
  void (*release_voice)(int32_t);
  void (*start_voice)(int32_t);
  void (*stop_voice)(int32_t);
  void (*loop_voice)(int32_t, int32_t);
  int32_t (*get_position)(int32_t);
  void (*set_position)(int32_t, int32_t);
  int32_t (*get_volume)(int32_t);
  void (*set_volume)(int32_t, int32_t);
  void (*ramp_volume)(int32_t, int32_t, int32_t);
  void (*stop_volume_ramp)(int32_t);
  int32_t (*get_frequency)(int32_t);
  void (*set_frequency)(int32_t, int32_t);
  void (*sweep_frequency)(int32_t, int32_t, int32_t);
  void (*stop_frequency_sweep)(int32_t);
  int32_t (*get_pan)(int32_t);
  void (*set_pan)(int32_t, int32_t);
  void (*sweep_pan)(int32_t, int32_t, int32_t);
  void (*stop_pan_sweep)(int32_t);
  void (*set_echo)(int32_t, int32_t, int32_t);
  void (*set_tremolo)(int32_t, int32_t, int32_t);
  void (*set_vibrato)(int32_t, int32_t, int32_t);
  int32_t rec_cap_bits;
  int32_t rec_cap_stereo;
  int32_t (*rec_cap_rate)(int32_t, int32_t);
  int32_t (*rec_cap_parm)(int32_t, int32_t, int32_t);
  int32_t (*rec_source)(int32_t);
  int32_t (*rec_start)(int32_t, int32_t, int32_t);
  void (*rec_stop)(void);
  int32_t (*rec_read)(void*);
};

struct VOICEINFO_ {
  int32_t sndId;
  int32_t voice;
  undefined4 _unknown;
};

struct MUSIC_INFO_ {
  int32_t max_chn;
  int32_t no_chn;
  int32_t tick;
  int32_t pos;
  int32_t pat;
  int32_t trk;
  int32_t flag;
  int32_t bpm;
  int32_t tempo;
  int32_t speed_ratio;
  int32_t pitch_ratio;
  int32_t global_volume;
  int32_t new_pos;
  int32_t new_trk;
  int32_t pattern_delay;
  int32_t skip_pos;
  int32_t slip_trk;
  int32_t loop;
  int32_t pause;
  int32_t forbid;
  int32_t is_playing;
};

struct In_Module_ {
  int32_t version;
  char* description;
  HWND hMainWindow;
  HINSTANCE hDllInstance;
  char* FileExtensions;
  int32_t is_seekable;
  int32_t UsesOutputPlug;
  void (*config)(HWND);
  void (*about)(HWND);
  void (*init)(void);
  void (*quit)(void);
  void (*getFileInfo)(char*, char*, int32_t*);
  int32_t (*infoBox)(char*, HWND);
  int32_t (*isOurFile)(char*);
  int32_t (*play)(char*);
  int32_t (*pause)(int32_t);
  void (*unPause)(void);
  int32_t (*isPaused)(void);
  void (*stop)(void);
  int32_t (*getLength)(void);
  int32_t (*getOutputTime)(void);
  void (*setOutputTime)(int32_t);
  void (*setVolume)(int32_t);
  void (*setPan)(int32_t);
  void (*savsaInit)(int32_t, int32_t);
  void (*savsaDeInit)(void);
  void (*saAddPCMData)(void*, int32_t, int32_t, int32_t);
  int32_t (*saGetMode)(void);
  void (*saAdd)(void*, int32_t, int32_t);
  void (*vsaAddPCMData)(void*, int32_t, int32_t, int32_t);
  int32_t (*vsaGetMode)(int32_t*, int32_t*);
  void (*vsaAdd)(void*, int32_t);
  void (*vsaSetInfo)(int32_t, int32_t);
  int32_t (*dspIsActive)(void);
  int32_t (*dspDoSamples)(int16_t*, int32_t, int32_t, int32_t, int32_t);
  void (*eqSet)(int32_t, char[10], int32_t);
  void (*setInfo)(int32_t, int32_t, int32_t, int32_t);
  Out_Module* outMod;
};
struct Out_Module_ {
  int32_t version;
  char* description;
  int32_t id;
  HWND hMainWindow;
  HINSTANCE hDllInstance;
  void (*config)(HWND);
  void (*about)(HWND);
  void (*init)(void);
  void (*quit)(void);
  int32_t (*open)(int32_t, int32_t, int32_t, int32_t, int32_t);
  void (*close)(void);
  int32_t (*write)(char*, int32_t);
  int32_t (*canWrite)(void);
  int32_t (*isPlaying)(void);
  int32_t (*pause)(int32_t);
  void (*setVolume)(int32_t);
  void (*setPan)(int32_t);
  void (*flush)(int32_t);
  int32_t (*getOutputTime)(void);
  int32_t (*getWrittenTime)(void);
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MIDI_TRACK_ {
  uint8_t* data;
  int32_t len;
};
struct MIDI_ {
  int32_t divisions;
  MIDI_TRACK track[32];
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct KB_BUFFER_ {
  char c[1024];
  undefined4 _unknown_1;
  undefined4 _unknown_2;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct PACKFILE_ {
  int32_t hndl;
  int32_t flags;
  uint8_t* buf_pos;
  int32_t buf_size;
  PACKFILE* parent;
  void* pack_data;
  char* filename;
  char* passdata;
  char* passdos;
  uint8_t buf[4096];
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MUGEN_FONT_ {
  int32_t fontNo;
  int32_t fontBank;
  int32_t alignMt;
};
struct MUGEN_SOUND_ {
  int32_t groupNo;
  int32_t itemNo;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MUGEN_PLAYER_REDIRECTS {
  MUGEN_PLAYER* enemyFirst;
  MUGEN_PLAYER* teamFirst;
  MUGEN_PLAYER* partner;
  MUGEN_PLAYER* parent;
  MUGEN_PLAYER* root;
};

struct MUGEN_PAL_FX_ {
  int32_t elapsedTime;
  int32_t time;
  int32_t color;
  int32_t addR;
  int32_t addG;
  int32_t addB;
  int32_t mulR;
  int32_t mulG;
  int32_t mulB;
  int32_t sinAddR;
  int32_t sinAddG;
  int32_t sinAddB;
  uint32_t invertAll;
  uint32_t sinAddF;
  uint32_t resetFlag;
};
struct MUGEN_ENV_SHAKE_ {
  int32_t elapsedTime;
  int32_t time;
  int32_t dir;
  float freq;
  float ampl;
  float phase;
};
struct MUGEN_HIT_DEF_PARAMS_ {
  uint32_t isAttacking;
  uint32_t isHitDef;
  uint32_t affectTeam;
  uint32_t attr;
  int32_t attackNo;
  int32_t hitId;
  int32_t chainId;
  int32_t noChainId;
  int32_t noChainId2;
  uint32_t kill;
  uint32_t guard_kill;
  uint32_t fall_kill;
  uint32_t hitOnce;
  int32_t jugglePoints;
  int32_t damage;
  int32_t guard_damage;
  int32_t getPower;
  int32_t guard_getPower;
  int32_t givePower;
  int32_t guard_givePower;
  int32_t p2HitPauseTime;
  int32_t p1HitPauseTime;
  int32_t numHits;
  MUGEN_SOUND hitSound;
  uint32_t hitSoundFlag; /* S: 0, F: 1 */
  MUGEN_SOUND guardSound;
  uint32_t guardSoundFlag; /* S: 0, F: 1 */
  uint32_t guardFlag;
  uint32_t hitFlag;
  int32_t hitPriority;
  uint32_t hitPriorityType;
  int32_t attackWidthZ1;
  int32_t attackWidthZ2;
  int32_t p1StateNo;
  int32_t p2StateNo;
  uint32_t p2GetP1StateNo;
  int32_t p2BindTime;
  int32_t p1SprPriority;
  int32_t p2SprPriority;
  uint32_t animType;
  uint32_t forceStand;
  uint32_t reversalAttr;
  int32_t fall_damage;
  uint32_t fall_animType;
  float fall_XVelocity;
  float fall_YVelocity;
  uint32_t fall_recover;
  int32_t fall_recover_time;
  MUGEN_ENV_SHAKE fall_envShake;
  int32_t sparkNo;
  uint32_t sSparkFlag; /* S: 1, F: 0 */
  int32_t guard_sparkNo;
  uint32_t guard_sSparkFlag; /* S: 1, F: 0 */
  int32_t sparkX;
  int32_t sparkY;
  int32_t p1Facing;
  int32_t p1GetP2Facing;
  int32_t minDistX;
  int32_t minDistY;
  int32_t minDistZ;
  int32_t maxDistX;
  int32_t maxDistY;
  int32_t maxDistZ;
  int32_t p2Facing;
  uint32_t ground_type;
  int32_t ground_hitTime;
  int32_t ground_slideTime;
  float ground_velocityX;
  float ground_velocityY;
  float ground_cornerPush_velOff;
  uint32_t air_type;
  uint32_t air_animType;
  int32_t air_hitTime;
  uint32_t air_fall;
  float air_velocityX;
  float air_velocityY;
  float air_cornerPush_velOff;
  uint32_t down_bounce;
  int32_t down_hitTime;
  float down_velocityX;
  float down_velocityY;
  float down_cornerPush_velOff;
  float guard_velocity;
  int32_t guard_hitTime;
  int32_t guard_slideTime;
  int32_t guard_ctrlTime;
  int32_t guard_dist;
  int32_t guard_p2PauseTime;
  int32_t guard_p1PauseTime;
  float guard_cornerPush_velOff;
  float airGuard_velocityX;
  float airGuard_velocityY;
  int32_t airGuard_ctrlTime;
  float airGuard_cornerPush_velOff;
  float YAccel;
  MUGEN_PAL_FX palFX;
  MUGEN_ENV_SHAKE envShake;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

union MUGEN_EVAL_NODE_ {
  int32_t i;
  float f;
  MUGEN_EVAL_TYPE t;
};
struct MUGEN_EVAL_VALUE_ {
  MUGEN_EVAL_EXPR_VALUE* exprs;
  MUGEN_EVAL_TYPE* types; /* 0: immediate value */
  MUGEN_EVAL_NODE value;  /* types == NULL => immediate value, otherwise length of types, exprs */
};
struct MUGEN_EVAL_TRIGGER_ {
  MUGEN_TRIG_ID trigID;
  MUGEN_REDIRECT_ID redirectID;
  MUGEN_EVAL_VALUE redirectArg;
  MUGEN_EVAL_COMPARATOR compareStyle;
  uint32_t isFloat;
  value32_t trigArgs[6];
  char* trigStrArg;
};
union MUGEN_EVAL_EXPR_VALUE_ {
  int32_t i;
  float f;
  MUGEN_EVAL_OPERATOR op;
  MUGEN_EVAL_TRIGGER* trig;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct ABSTRUCT_ARRAY_INFO_ {
  undefined4 _unknown;
  int32_t size; /* size of data structure */
  int32_t currentDataCnt;
  int32_t maxDataCnt;
  uint32_t nextID;
  void* user_definition_data;
  ABSTRUCT_ARRAY_LIST* arrayList;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct ABSTRUCT_ARRAY_LIST_ {
  uint32_t enable;
  int32_t id;   /* use for search */
  int32_t grp;  /* user definition param1 */
  int32_t item; /* user definition param2 */
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MUGEN_AFTERIMAGE_INFO_ {
  undefined4 _unknown;
  int32_t size;
  int32_t currentAfterImageCnt;
  int32_t maxAfterImageCnt;
  uint32_t nextId;
  MUGEN_AFTERIMAGE_DATA* data;
  MUGEN_AFTERIMAGE_LIST* list;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_AFTERIMAGE_DATA_ {
  MUGEN_AFTERIMAGE_PALLETES* palletes;
  int32_t length_maximum;
  MUGEN_ANIM_USED* anim;
  int32_t _unknown_2;
  int32_t _unknown_3;
  int32_t elapsedTime;
  uint32_t enable;
  int32_t time;
  int32_t length;
  int32_t timeGap;
  int32_t frameGap;
  int32_t palColor;
  uint32_t palInvertAll;
  int32_t palBrightR;
  int32_t palBrightG;
  int32_t palBrightB;
  int32_t palContrastR;
  int32_t palContrastG;
  int32_t palContrastB;
  int32_t palPostBrightR;
  int32_t palPostBrightG;
  int32_t palPostBrightB;
  int32_t palAddR;
  int32_t palAddG;
  int32_t palAddB;
  int32_t palMulR;
  int32_t palMulG;
  int32_t palMulB;
  MUGEN_TRANS_TYPE trans;
  int32_t transAlphaAS;
  int32_t transAlphaD;
};
struct MUGEN_AFTERIMAGE_LIST_ {
  uint32_t enable;
  int32_t id;
  int32_t _unknown;
  int32_t search_id;
};
struct MUGEN_AFTERIMAGE_PALLETES_ {
  int32_t _unknown_1;
  undefined4 _unknown_2;
  undefined4 _unknown_3;
  undefined4 _unknown_4;
  undefined4 _unknown_5;
  undefined4 _unknown_6;
  undefined4 _unknown_7;
  undefined4 _unknown_8;
  MUGEN_PALLETE_DATA* palletes;
  undefined4 _unknown_9[406];
};

struct MUGEN_ANIM_USED_ {
  MUGEN_ANIM_INFO_EX* useAnimInfoEx;
  MUGEN_SFF_INFO_EX* sff;
  undefined4 _unknown_1;
  int32_t currentAnimIndex;
  MUGEN_ANIM_ELEM_DATA* currentAnimElem;
  int32_t currentAnimElemIndex;
  int32_t totalElapsedFrames;
  int32_t currentFrame;
  MUGEN_TRANS_TYPE trans;
  int32_t transAlphaAS;
  int32_t transAlphaD;
  int32_t currentSpriteIndex;
  MUGEN_SFF_INFO_EX* spritesLayer; /* Ontop == 0: g->prioritySpritesLayer1, Otherwise: NULL */
  int32_t sprPriority;
};
struct MUGEN_ANIM_INFO_EX_ {
  MUGEN_ANIM_INFO* info;
  int32_t totalAnims;
};
struct MUGEN_ANIM_INFO_ {
  undefined4 _unknown;
  int32_t size;
  int32_t maxAnimIndex;
  int32_t currentAnimCnt;
  int32_t nextId;
  MUGEN_ANIM_DATA* data;
  MUGEN_ANIM_LIST* list;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_ANIM_DATA_ {
  MUGEN_ANIM_ELEM_INFO* info;
  int32_t totalElems;
  int32_t totalFrames;
  int32_t loopStartFrame;
};
struct MUGEN_ANIM_LIST_ {
  uint32_t enable;
  int32_t id;
  int32_t _unknown_1;
  int32_t animNo;
};

struct MUGEN_ANIM_ELEM_INFO_ {
  uint32_t enable;
  int32_t size;
  int32_t currentElemCnt;
  int32_t maxElemCnt;
  int32_t nextId;
  MUGEN_ANIM_ELEM_DATA* data;
  MUGEN_ANIM_ELEM_LIST* list;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_ANIM_ELEM_DATA_ {
  int32_t startFrame;
  int32_t displayTime;
  int32_t groupNo;
  int32_t itemNo;
  int32_t axisX;
  int32_t axisY;
  uint32_t inverse; /* &1: H, &2: V */
  MUGEN_TRANS_TYPE trans;
  int32_t transAlphaAS;
  int32_t transAlphaD;
  MUGEN_CLSN_INFO* clsn1;
  MUGEN_CLSN_INFO* clsn2;
};
struct MUGEN_ANIM_ELEM_LIST_ {
  uint32_t enable;
  int32_t id;
  int32_t _unknown;
  int32_t elemNo;
};

struct MUGEN_CLSN_INFO_ {
  uint32_t enable;
  int32_t clsn_cnt;
  MUGEN_CLSN_DATA* data;
};
struct MUGEN_CLSN_DATA_ {
  undefined4 _unknown;
  int32_t x_back;
  int32_t y_bottom;
  int32_t x_front;
  int32_t x_upper;
};

struct MUGEN_SFF_INFO_EX_ {
  MUGEN_SFF_INFO* sffInfo;
  void* _unknown_1;
  MUGEN_PALLETE_INFO* pallete;
  MUGEN_SFF_INFO_EX* field3_0xc;
  int32_t refCnt;
};
struct MUGEN_SFF_INFO_ {
  undefined4 _unknown;
  int32_t size;
  int32_t currentSffCnt;
  int32_t maxSffCnt;
  int32_t nextId;
  MUGEN_SFF_DATA* data;
  MUGEN_SFF_LIST* list;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_SFF_DATA_ {
  int32_t width;
  int32_t height;
  int32_t axisX;
  int32_t axisY;
  int32_t colorDepth;
  int32_t colors;
  undefined4 _unknown_1;
  uint32_t isAllegroBitmap;
  int32_t size;
  void* image; /* If isAllegroBitmap == 1 then BITMAP*, otherwise decoded pcx data */
  undefined4 _unknown_2;
  void* _unknown_3;
  int32_t palleteIndex;
};
struct MUGEN_SFF_LIST_ {
  uint32_t enable;
  int32_t id;
  int32_t groupNo;
  int32_t itemNo;
};

struct MUGEN_PALLETE_INFO_ {
  undefined4 _unknown_1;
  int32_t size;
  int32_t currentPalleteCnt;
  int32_t maxPalleteCnt;
  int32_t nextId;
  MUGEN_PALLETE_DATA* data;
  MUGEN_PALLETE_LIST* list;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_PALLETE_DATA_RGB_ {
  uint32_t r;
  uint32_t g;
  uint32_t b;
  undefined4 _unknown; /* Alpha? Padding? */
};
struct MUGEN_PALLETE_PARAMS_ {
  undefined4 _unknown[9];
};
struct MUGEN_PALLETE_DATA_ {
  undefined4 size;
  uint32_t enable;
  MUGEN_PALLETE_DATA_RGB* rgbData;
  MUGEN_PALLETE_PARAMS _unknown_1;
  MUGEN_PALLETE_PARAMS _unknown_2;
  undefined4 _unknown_3;
  undefined4 _unknown_4;
  MUGEN_PALLETE_DATA_RGB _unknown_5[];
};
struct MUGEN_PALLETE_LIST_ {
  uint32_t enable;
  int32_t id;
  int32_t _unknown_1;
  int32_t _unknown_2;
};

struct MUGEN_SND_INFO_ {
  undefined4 _unknown;
  int32_t size;
  int32_t currentSndCnt;
  int32_t maxSndCnt;
  int32_t nextId;
  MUGEN_SND_DATA* data;
  MUGEN_SND_LIST* list;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_SND_DATA_ {
  SAMPLE* sound;
};
struct MUGEN_SND_LIST_ {
  uint32_t enable;
  int32_t id;
  int32_t groupNo;
  int32_t itemNo;
};

struct MUGEN_STATE_DEF_INFO_ {
  undefined4 _unknown;
  int32_t size;
  int32_t currentDefCnt;
  int32_t maxDefCnt;
  int32_t nextId;
  MUGEN_STATE_DEF_DATA* defData;
  MUGEN_STATE_DEF_LIST* defList;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_STATE_DEF_DATA_ {
  MUGEN_SC_INFO* states;
  MUGEN_PLAYER_STATETYPE type;
  MUGEN_PLAYER_MOVETYPE moveType;
  MUGEN_PLAYER_PHYSICS physics;
  MUGEN_EVAL_VALUE juggle;
  MUGEN_EVAL_VALUE faceP2;
  MUGEN_EVAL_VALUE hitDefPersist;
  MUGEN_EVAL_VALUE hitCountPersist;
  MUGEN_EVAL_VALUE moveHitPersist;
  int sprPriorityFlag;
  MUGEN_EVAL_VALUE sprPriority;
  MUGEN_EVAL_VALUE velSetX;
  MUGEN_EVAL_VALUE velSetY;
  MUGEN_EVAL_VALUE velSetZ;
  MUGEN_EVAL_VALUE ctrl;
  MUGEN_EVAL_VALUE anim;
  MUGEN_EVAL_VALUE powerAdd;
};
struct MUGEN_STATE_DEF_LIST_ {
  uint32_t enable;
  int32_t id;
  int32_t stateNo;
  undefined4 _unknown;
};

struct MUGEN_SC_INFO_ {
  undefined4 _unknown;
  int32_t size;
  int32_t currentSCCnt;
  int32_t maxSCCnt;
  int32_t nextId;
  MUGEN_SC_DATA* scData;
  MUGEN_SC_LIST* scList;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_SC_LIST_ {
  uint32_t enable;
  int32_t id;
  MUGEN_SC_ID scID;
  int32_t laterLabelNo;
};
struct MUGEN_SC_PARAMS_EX_HITOVERRIDE_ {
  uint32_t attr;
  MUGEN_EVAL_VALUE stateNo;
  MUGEN_EVAL_VALUE time;
  MUGEN_EVAL_VALUE forceAir;
};
struct MUGEN_SC_PARAMS_EX_ENVSHAKE_ {
  MUGEN_EVAL_VALUE time;
  MUGEN_EVAL_VALUE dir;
  MUGEN_EVAL_VALUE freq;
  MUGEN_EVAL_VALUE ampl;
  MUGEN_EVAL_VALUE phase;
  uint32_t _unknown;
};
struct MUGEN_SC_PARAMS_EX_AFTERIMAGE_ {
  MUGEN_EVAL_VALUE time;
  MUGEN_EVAL_VALUE length;
  MUGEN_EVAL_VALUE timeGap;
  MUGEN_EVAL_VALUE frameGap;
  MUGEN_EVAL_VALUE palColor;
  MUGEN_EVAL_VALUE palInvertAll;
  MUGEN_EVAL_VALUE palBright_R;
  MUGEN_EVAL_VALUE palBright_G;
  MUGEN_EVAL_VALUE palBright_B;
  MUGEN_EVAL_VALUE palContrast_R;
  MUGEN_EVAL_VALUE palContrast_G;
  MUGEN_EVAL_VALUE palContrast_B;
  MUGEN_EVAL_VALUE palPostBright_R;
  MUGEN_EVAL_VALUE palPostBright_G;
  MUGEN_EVAL_VALUE palPostBright_B;
  MUGEN_EVAL_VALUE palAdd_R;
  MUGEN_EVAL_VALUE palAdd_G;
  MUGEN_EVAL_VALUE palAdd_B;
  MUGEN_EVAL_VALUE palMul_R;
  MUGEN_EVAL_VALUE palMul_G;
  MUGEN_EVAL_VALUE palMul_B;
  MUGEN_TRANS_TYPE trans;
  MUGEN_EVAL_VALUE alphaAS;
  MUGEN_EVAL_VALUE alphaD;
};
struct MUGEN_SC_PARAMS_EX_PAUSE_ {
  MUGEN_EVAL_VALUE time;
  MUGEN_EVAL_VALUE moveTime;
  MUGEN_EVAL_VALUE endCmdBufTime;
  MUGEN_EVAL_VALUE pauseBG;
};
struct MUGEN_SC_PARAMS_EX_SUPERPAUSE_ {
  MUGEN_EVAL_VALUE time;
  MUGEN_EVAL_VALUE moveTime;
  MUGEN_EVAL_VALUE endCmdBufTime;
  MUGEN_EVAL_VALUE pauseBG;
  uint32_t animFlag; /* S: 1, F: 0 */
  MUGEN_EVAL_VALUE anim;
  MUGEN_EVAL_VALUE posX;
  MUGEN_EVAL_VALUE posY;
  MUGEN_EVAL_VALUE darken;
  MUGEN_EVAL_VALUE p2DefMul;
  MUGEN_EVAL_VALUE powerAdd;
  MUGEN_EVAL_VALUE unhittable;
  uint32_t soundFlag; /* S: 0, F: 1 */
  MUGEN_EVAL_VALUE soundGrpNo;
  MUGEN_EVAL_VALUE soundItemNo;
};
struct MUGEN_SC_PARAMS_EX_PALFX_ {
  uint32_t flag; /* 1: BGPalFX, 2: AllPalFX, otherwise: PalFX */
  MUGEN_EVAL_VALUE time;
  MUGEN_EVAL_VALUE color;
  MUGEN_EVAL_VALUE add_R;
  MUGEN_EVAL_VALUE add_G;
  MUGEN_EVAL_VALUE add_B;
  MUGEN_EVAL_VALUE mul_R;
  MUGEN_EVAL_VALUE mul_G;
  MUGEN_EVAL_VALUE mul_B;
  MUGEN_EVAL_VALUE sinAdd_R;
  MUGEN_EVAL_VALUE sinAdd_G;
  MUGEN_EVAL_VALUE sinAdd_B;
  MUGEN_EVAL_VALUE invertAll;
  MUGEN_EVAL_VALUE sinAdd_F;
};
struct MUGEN_SC_PARAMS_EX_EXPLOD_ {
  MUGEN_EVAL_VALUE id;
  MUGEN_EVAL_VALUE anim;
  uint32_t animFlag; /* S: 0, F: 1 */
  MUGEN_EVAL_VALUE posX;
  MUGEN_EVAL_VALUE posY;
  MUGEN_EVAL_VALUE velX;
  MUGEN_EVAL_VALUE velY;
  MUGEN_EVAL_VALUE accelX;
  MUGEN_EVAL_VALUE accelY;
  MUGEN_EVAL_VALUE randomX;
  MUGEN_EVAL_VALUE randomY;
  MUGEN_EVAL_VALUE superMove;
  MUGEN_EVAL_VALUE superMoveTime;
  MUGEN_EVAL_VALUE pauseMoveTime;
  MUGEN_EVAL_VALUE removeTime;
  MUGEN_EVAL_VALUE scaleX;
  MUGEN_EVAL_VALUE scaleY;
  uint32_t posType; /* P1: 0, Front: 1, Back: 2, Left: 3, Right: 4, P2: 5 */
  MUGEN_EVAL_VALUE bindTime;
  MUGEN_EVAL_VALUE sprPriority;
  MUGEN_EVAL_VALUE onTop;
  MUGEN_EVAL_VALUE facing;
  MUGEN_EVAL_VALUE vFacing;
  MUGEN_EVAL_VALUE shadow_R;
  MUGEN_EVAL_VALUE shadow_G;
  MUGEN_EVAL_VALUE shadow_B;
  MUGEN_EVAL_VALUE ownPal;
  MUGEN_EVAL_VALUE removeOnGetHit;
  MUGEN_EVAL_VALUE ignoreHitPause;
  MUGEN_TRANS_TYPE trans;
  MUGEN_EVAL_VALUE alphaAS;
  MUGEN_EVAL_VALUE alphaD;
};
struct MUGEN_SC_PARAMS_EX_HELPER_ {
  char name[48];
  MUGEN_EVAL_VALUE id;
  uint32_t playerType;
  MUGEN_EVAL_VALUE posX;
  MUGEN_EVAL_VALUE posY;
  uint32_t posType;
  MUGEN_EVAL_VALUE facing;
  MUGEN_EVAL_VALUE stateNo;
  MUGEN_EVAL_VALUE keyCtrl;
  MUGEN_EVAL_VALUE ownPal;
  MUGEN_EVAL_VALUE superMoveTime;
  MUGEN_EVAL_VALUE pauseMoveTime;
  MUGEN_EVAL_VALUE size_XScale;
  MUGEN_EVAL_VALUE size_YScale;
  MUGEN_EVAL_VALUE size_ground_back;
  MUGEN_EVAL_VALUE size_ground_front;
  MUGEN_EVAL_VALUE size_air_back;
  MUGEN_EVAL_VALUE size_air_front;
  MUGEN_EVAL_VALUE size_height;
  MUGEN_EVAL_VALUE size_proj_doScale;
  MUGEN_EVAL_VALUE size_head_pos_x;
  MUGEN_EVAL_VALUE size_head_pos_y;
  MUGEN_EVAL_VALUE size_mid_pos_x;
  MUGEN_EVAL_VALUE size_mid_pos_y;
  MUGEN_EVAL_VALUE size_shadowOffset;
};
struct MUGEN_SC_PARAMS_EX_CLIPBOARD_ {
  char text[256];
};
struct MUGEN_SC_PARAMS_EX_PLAYSND_ {
  MUGEN_EVAL_VALUE channel;
  MUGEN_EVAL_VALUE sndGroupNo;
  MUGEN_EVAL_VALUE sndItemNo;
  MUGEN_EVAL_VALUE volume;
  uint32_t sndFlag; /* S: 0, F: 1 */
  MUGEN_EVAL_VALUE lowPriority;
  MUGEN_EVAL_VALUE freqMul;
  MUGEN_EVAL_VALUE loop;
  uint32_t panType; /* 0: Pan, Otherwise: AbsPan */
  MUGEN_EVAL_VALUE pan;
};
struct MUGEN_SC_PARAMS_EX_HITDEF_ {
  uint32_t affectTeam;
  uint32_t attr;
  MUGEN_EVAL_VALUE id;
  MUGEN_EVAL_VALUE chainId;
  MUGEN_EVAL_VALUE noChainId;
  MUGEN_EVAL_VALUE noChainId2;
  MUGEN_EVAL_VALUE kill;
  MUGEN_EVAL_VALUE guard_kill;
  MUGEN_EVAL_VALUE fall_kill;
  MUGEN_EVAL_VALUE hitOnce;
  MUGEN_EVAL_VALUE juggle;
  MUGEN_EVAL_VALUE damage;
  MUGEN_EVAL_VALUE guard_damage;
  MUGEN_EVAL_VALUE getPower;
  MUGEN_EVAL_VALUE guard_getPower;
  MUGEN_EVAL_VALUE givePower;
  MUGEN_EVAL_VALUE guard_givePower;
  MUGEN_EVAL_VALUE p2HitPauseTime;
  MUGEN_EVAL_VALUE p1HitPauseTime;
  MUGEN_EVAL_VALUE numHits;
  MUGEN_EVAL_VALUE hitSound_groupNo;
  MUGEN_EVAL_VALUE hitSound_itemNo;
  uint32_t hitSoundFlag;
  MUGEN_EVAL_VALUE guardSound_groupNo;
  MUGEN_EVAL_VALUE guardSound_itemNo;
  uint32_t guardSoundFlag;
  uint32_t guardFlag;
  uint32_t hitFlag;
  MUGEN_EVAL_VALUE hitPriority;
  uint32_t hitPriorityType;
  MUGEN_EVAL_VALUE attackWidthZ1;
  MUGEN_EVAL_VALUE attackWidthZ2;
  MUGEN_EVAL_VALUE p1StateNo;
  MUGEN_EVAL_VALUE p2StateNo;
  MUGEN_EVAL_VALUE p2GetP1StateNo;
  MUGEN_EVAL_VALUE p2BindTime;
  MUGEN_EVAL_VALUE p1SprPriority;
  MUGEN_EVAL_VALUE p2SprPriority;
  uint32_t animType;
  MUGEN_EVAL_VALUE forceStand;
  uint32_t hasForceStand;
  uint32_t reversalAttr;
  MUGEN_EVAL_VALUE fall_damage;
  uint32_t fall_animType;
  MUGEN_EVAL_VALUE fall_XVelocity;
  MUGEN_EVAL_VALUE fall_YVelocity;
  MUGEN_EVAL_VALUE fall_recover;
  MUGEN_EVAL_VALUE fall_recover_time;
  MUGEN_SC_PARAMS_EX_ENVSHAKE fall_envShake;
  MUGEN_EVAL_VALUE fall;
  MUGEN_EVAL_VALUE sparkNo;
  uint32_t sSparkFlag;
  MUGEN_EVAL_VALUE guard_sparkNo;
  uint32_t guard_sSparkFlag;
  MUGEN_EVAL_VALUE sparkX;
  MUGEN_EVAL_VALUE sparkY;
  MUGEN_EVAL_VALUE p1Facing;
  MUGEN_EVAL_VALUE p1GetP2Facing;
  MUGEN_EVAL_VALUE minDistX;
  MUGEN_EVAL_VALUE minDistY;
  MUGEN_EVAL_VALUE minDistZ;
  MUGEN_EVAL_VALUE maxDistX;
  MUGEN_EVAL_VALUE maxDistY;
  MUGEN_EVAL_VALUE maxDistZ;
  MUGEN_EVAL_VALUE p2Facing;
  uint32_t ground_type;
  MUGEN_EVAL_VALUE ground_hitTime;
  MUGEN_EVAL_VALUE ground_slideTime;
  MUGEN_EVAL_VALUE ground_velocityX;
  MUGEN_EVAL_VALUE ground_velocityY;
  MUGEN_EVAL_VALUE ground_cornerPush_velOff;
  uint32_t air_type;
  uint32_t air_animType;
  MUGEN_EVAL_VALUE air_hitTime;
  MUGEN_EVAL_VALUE air_fall;
  MUGEN_EVAL_VALUE air_velocityX;
  MUGEN_EVAL_VALUE air_velocityY;
  MUGEN_EVAL_VALUE air_cornerPush_velOff;
  MUGEN_EVAL_VALUE down_bounce;
  MUGEN_EVAL_VALUE down_hitTime;
  MUGEN_EVAL_VALUE down_velocityX;
  MUGEN_EVAL_VALUE down_velocityY;
  MUGEN_EVAL_VALUE down_cornerPush_velOff;
  MUGEN_EVAL_VALUE guard_velocity;
  MUGEN_EVAL_VALUE guard_hitTime;
  MUGEN_EVAL_VALUE guard_slideTime;
  MUGEN_EVAL_VALUE guard_ctrlTime;
  MUGEN_EVAL_VALUE guard_dist;
  MUGEN_EVAL_VALUE guard_p2PauseTime;
  MUGEN_EVAL_VALUE guard_p1PauseTime;
  MUGEN_EVAL_VALUE guard_cornerPush_velOff;
  MUGEN_EVAL_VALUE airGuard_velocityX;
  MUGEN_EVAL_VALUE airGuard_velocityY;
  MUGEN_EVAL_VALUE airGuard_ctrlTime;
  MUGEN_EVAL_VALUE airGuard_cornerPush_velOff;
  MUGEN_EVAL_VALUE YAccel;
  MUGEN_SC_PARAMS_EX_PALFX palFX;
  MUGEN_SC_PARAMS_EX_ENVSHAKE envShake;
};
struct MUGEN_SC_PARAMS_EX_PROJECTILE_ {
  MUGEN_EVAL_VALUE projId;
  MUGEN_EVAL_VALUE posX;
  MUGEN_EVAL_VALUE posY;
  uint32_t posType;
  MUGEN_EVAL_VALUE projRemove;
  MUGEN_EVAL_VALUE projRemoveTime;
  MUGEN_EVAL_VALUE projMissTime;
  MUGEN_EVAL_VALUE projEdgeBound;
  MUGEN_EVAL_VALUE projStageBound;
  MUGEN_EVAL_VALUE projHeightBoundUpper;
  MUGEN_EVAL_VALUE projHeightBoundBottom;
  MUGEN_EVAL_VALUE projHits;
  MUGEN_EVAL_VALUE projPriority;
  MUGEN_EVAL_VALUE projAnim;
  MUGEN_EVAL_VALUE projHitAnim;
  MUGEN_EVAL_VALUE projRemAnim;
  MUGEN_EVAL_VALUE projCancelAnim;
  MUGEN_EVAL_VALUE projShadow_R;
  MUGEN_EVAL_VALUE projShadow_G;
  MUGEN_EVAL_VALUE projShadow_B;
  MUGEN_EVAL_VALUE projSprPriority;
  MUGEN_EVAL_VALUE velocityX;
  MUGEN_EVAL_VALUE velocityY;
  MUGEN_EVAL_VALUE velMulX;
  MUGEN_EVAL_VALUE velMulY;
  MUGEN_EVAL_VALUE remVelocityX;
  MUGEN_EVAL_VALUE remVelocityY;
  MUGEN_EVAL_VALUE accelX;
  MUGEN_EVAL_VALUE accelY;
  MUGEN_EVAL_VALUE projScaleX;
  MUGEN_EVAL_VALUE projScaleY;
  MUGEN_EVAL_VALUE pauseMoveTime;
  MUGEN_EVAL_VALUE superMoveTime;
  MUGEN_SC_PARAMS_EX_HITDEF hitDefParams;
  MUGEN_SC_PARAMS_EX_AFTERIMAGE* afterImage;
};
union MUGEN_SC_PARAMS_EX_ {
  MUGEN_SC_PARAMS_EX_HITOVERRIDE* hitOverride;
  MUGEN_SC_PARAMS_EX_ENVSHAKE* envShake;
  MUGEN_SC_PARAMS_EX_AFTERIMAGE* afterImage;
  MUGEN_SC_PARAMS_EX_PAUSE* pause;
  MUGEN_SC_PARAMS_EX_SUPERPAUSE* superPause;
  MUGEN_SC_PARAMS_EX_PALFX* palFX;
  MUGEN_SC_PARAMS_EX_EXPLOD* explod;
  MUGEN_SC_PARAMS_EX_HELPER* helper;
  MUGEN_SC_PARAMS_EX_CLIPBOARD* clipboard;
  MUGEN_SC_PARAMS_EX_PLAYSND* playSnd;
  MUGEN_SC_PARAMS_EX_HITDEF* hitDef;
  MUGEN_SC_PARAMS_EX_PROJECTILE* projectile;
};
struct MUGEN_SC_DATA_ {
  MUGEN_TRIGGER_INFO* triggers;
  uint32_t triggerCnt;
  int32_t persistent;
  int32_t ignorehitpause;
  MUGEN_SC_ID scID;
  undefined4 _unknown_1;
  MUGEN_EVAL_VALUE params[6];
  MUGEN_SC_PARAMS_EX paramsEx;
};

struct MUGEN_TRIGGER_INFO_ {
  undefined4 _unknown;
  int32_t size;
  int32_t currentTrigCnt;
  int32_t maxTrigCnt;
  int32_t nextId;
  MUGEN_TRIGGER_DATA* trigData;
  MUGEN_TRIGGER_LIST* trigList;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_TRIGGER_DATA_ {
  MUGEN_EVAL_VALUE value;
};
struct MUGEN_TRIGGER_LIST_ {
  uint32_t enable;
  uint32_t id;
  int32_t triggerNo;
  int32_t triggerSubNo;
};

struct MUGEN_TARGET_INFO_ {
  undefined4 _unknown;
  int32_t size;
  int32_t currentTargetCnt;
  int32_t maxTargetCnt;
  int32_t nextId;
  MUGEN_TARGET_DATA* targetData;
  MUGEN_TARGET_LIST* targetList;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_TARGET_DATA_ {
  MUGEN_PLAYER* player;
  int32_t airJuggle;
  int32_t getTargetAt;
  int32_t bindPosX;
  int32_t bindPosY;
  int32_t bindPosZ;
  int32_t bindTime;
  int32_t preBindTime;
};
struct MUGEN_TARGET_LIST_ {
  uint32_t enable;
  int32_t id;
  undefined4 _unknown_1;
  undefined4 _unknown_2;
};

struct MUGEN_PROJECTILE_INFO_EX_ {
  MUGEN_PROJECTILE_INFO* projInfo;
  MUGEN_ANIM_INFO_EX* animInfo;
  MUGEN_SFF_INFO_EX* sffInfo;
};
struct MUGEN_PROJECTILE_INFO_ {
  undefined4 _unknown;
  int32_t size;
  int32_t currentProjCnt;
  int32_t maxProjCnt;
  uint32_t nextID;
  MUGEN_PROJECTILE_DATA* data;
  MUGEN_PROJECTILE_LIST* list;
  int32_t scaned_index;
  int32_t scaned_cnt;
  int32_t min_index;
  int32_t max_index;
};
struct MUGEN_PROJECTILE_DATA_ {
  int32_t projId;
  int32_t status;
  int32_t teamSide;
  int32_t projPriority;
  int32_t projHitAnim;
  int32_t projRemAnim;
  int32_t projCancelAnim;
  int32_t projHits;
  int32_t elapsedTime;
  int32_t time;
  int32_t projBindTime;
  undefined4 _unknown_1;
  int32_t projMissTime;
  int32_t facing;
  uint32_t projRemove;
  int32_t projRemoveTime;
  uint32_t projShadow;
  float posX;
  float posY;
  float posZ;
  float projScale;
  float projScaleX;
  float projScaleY;
  undefined4 _unknown_2;
  undefined4 _unknown_3;
  float velocityX;
  float velocityY;
  float remVelocityX;
  float remVelocityY;
  float velMulX;
  float velMulY;
  float accelX;
  float accelY;
  int32_t projEdgeBound;
  int32_t projStageBoundLeft;
  int32_t projHeightBoundUpper;
  int32_t projStageBoundRight;
  int32_t projHeightBoundBottom;
  MUGEN_HIT_DEF_PARAMS projHitDefParams;
  MUGEN_ANIM_USED* anim;
  undefined4 sff;
  undefined4 _unknown_4;
  undefined4 _unknown_5;
  undefined4 _unknown_6;
  undefined4 _unknown_7;
  undefined4 _unknown_8;
  undefined4 _unknown_9;
  undefined4 _unknown_10;
  undefined4 _unknown_11;
  undefined4 _unknown_12;
  undefined4 _unknown_13;
  undefined4 _unknown_14;
  undefined4 _unknown_15;
  int32_t projSprPriority;
  undefined4 _unknown_16;
  undefined4 _unknown_17;
  undefined4 _unknown_18;
  undefined4 _unknown_19;
  int32_t superMoveTime;
  int32_t pauseMoveTime;
  MUGEN_AFTERIMAGE_DATA* afterImage;
};
struct MUGEN_PROJECTILE_LIST_ {
  uint32_t enable;
  int32_t id;
  int32_t _unknown_1;
  int32_t _unknown_2;
};

struct MUGEN_EXPLODS_INFO_ {
  MUGEN_EXPLODS_DATA* data;
  int32_t explodsMax;
  int32_t explodsCnt;
};
struct MUGEN_EXPLODS_DATA_ {
  uint32_t exists;
  uint32_t visible;
  uint32_t invisible;
  int32_t ownerPlayerId;
  int32_t id;
  float axisX;
  float axisY;
  float velX;
  float velY;
  float accelX;
  float accelY;
  int32_t offsetX;
  int32_t offsetY;
  int32_t pauseMoveTime;
  int32_t superMoveTime;
  int32_t elapsedTime;
  int32_t removeTime;
  float scaleX;
  float scaleY;
  float* basePlayerRealPosX;
  float* basePlayerRealPosY;
  int32_t* stagePosX;
  int32_t* stagePosY;
  uint32_t posType; /* 0: P1, Front: 1, Back: 2, Left: 3, Right: 4, P2: 5 */
  int32_t bindTime;
  uint32_t layerNo;
  uint32_t inverse; /* &1: facing, &2: vfacing */
  undefined4 _unknown_1;
  undefined4 _unknown_2;
  uint32_t shadow;
  uint32_t removeOnGetHit;
  uint32_t ignoreHitPause;
  MUGEN_ANIM_USED* anim;
  MUGEN_TRANS_TYPE trans;
  int32_t transAlphaAS;
  int32_t transAlphaD;
  MUGEN_SFF_INFO_EX* sff;
  undefined4 _unknown_3;
  undefined4 _unknown_4[15];
  undefined4 _unknown_5;
  undefined4 _unknown_6;
  undefined4 _unknown_7;
  undefined4 _unknown_8;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MUGEN_SYSTEM_ANIM_ {
  int32_t anim;
  undefined4 _unknown_1;
  undefined4 _unknown_2;
  undefined4 _unknown_3;
  int32_t displayTime;
  int32_t offsetX;
  int32_t offsetY;
  int32_t layerNo;
  undefined4 _unknown_4;
  int32_t id;
  uint32_t facing;
  uint32_t vfacing;
  float scaleX;
  float scaleY;
};
struct MUGEN_SYSTEM_SPRITE_ {
  int32_t groupNo;
  int32_t itemNo;
  undefined4 _unknown_1;
  undefined4 _unknown_2;
  int32_t displayTime;
  int32_t offsetX;
  int32_t offsetY;
  int32_t layorNo;
  undefined4 _unknown_3;
  int32_t id;
  uint32_t facing;
  uint32_t vfacing;
  float scaleX;
  float scaleY;
};
struct MUGEN_SYSTEM_TEXT_ {
  MUGEN_FONT font;
  undefined4 _unknown_1;
  int32_t displayTime;
  int32_t offsetX;
  int32_t offsetY;
  int32_t layerNo;
  undefined4 _unknown_2;
  int32_t id;
  uint32_t facing;
  uint32_t vfacing;
  float scaleX;
  float scaleY;
  char text[48];
};
union MUGEN_SYSTEM_VIEW_COMPONENT_ {
  MUGEN_SYSTEM_ANIM anim;     /* if type == 1 */
  MUGEN_SYSTEM_SPRITE sprite; /* if type == 2 */
  MUGEN_SYSTEM_TEXT text;     /* if type == 3 */
};
struct MUGEN_SYSTEM_VIEW_ITEM_ {
  uint32_t type; /* 1: anim, 2: sprite, 3: text */
  MUGEN_SYSTEM_VIEW_COMPONENT item;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MUGEN_CONFIG_OPTIONS_ {
  int32_t difficulty;
  int32_t life;
  int32_t time;
  int32_t gameSpeed;
  int32_t wavVolume;
  int32_t midiVolume;
  undefined4 _unknown_1[16];
  int32_t team_1vs2life;
  uint32_t team_loseOnKO;
  undefined4 _unknown_2;
  undefined4 _unknown_3;
  char motif[512];
};
struct MUGEN_CONFIG_RULES_ {
  MUGEN_GAMETYPE gameType; /* "M*": 1, "V*": 0, otherwise: error */
  float default_attack_lifeToPowerMul;
  float default_getHit_lifeToPowerMul;
  float super_targetDefenceMul;
};
struct MUGEN_CONFIG_CONFIG_ {
  int32_t gameSpeed;
  int32_t drawShadows;
  int32_t afterImageMax;
  int32_t layeredSpriteMax;
  int32_t explodMax;
  int32_t sysExplodMax;
  int32_t helperMax;
  int32_t playerProjectileMax;
  int32_t playerPalMax;
  uint32_t firstRun;
};
struct MUGEN_CONFIG_VIDEO_WIN_ {
  int32_t width;
  int32_t height;
  int32_t depth;     /* depth? always 32 */
  uint32_t dxMode;   /* "f*": DXSA, "h*": DXAC, "n*": GDIB, "o*": DXOV, "s*": DXSO, "w*": DXWN */
  uint32_t blitMode; /* "n*": 0, "p*": 1, "t*": 2 */
  uint32_t stretch;
  int32_t doubleRes;
  uint32_t vRetrace; /* 0 */
};
struct MUGEN_CONFIG_SOUND_WIN_ {
  int32_t wavDevice;  /* -1: AUTO, 0: NONE, "DXA "-"DXJ ": DX0-DX9, "AXA "-"AXJ ": DXA0-DXA9, "WOA ": WAVEOUTA, "WOB ": WAVEOUTB */
  int32_t midiDevice; /* -1: AUTO, 0: NONE, "W32M": MAPPER, "W32A"-"W32J": MID0-MID9, "DIGI": DIGMID */
  int32_t wavChannels;
  int32_t modVoices;
  undefined4 _unknown; /* reverseStereo? */
  uint32_t playMP3;
  uint32_t playMIDI;
  uint32_t playMOD;
  uint32_t playCDA;
  char cdaDevice[32];
  uint32_t stereoEffects;
  int32_t panningWidth;
  int32_t pauseBGMOnDefocus;
};
struct MUGEN_CONFIG_SOUND_WIN2_ {
  uint32_t sound; /* If used "-nosound" or config's sound=0 then set to 0. */
  int32_t wavVolume;
  int32_t masterWavVolume;
  int32_t cdaVolume;
  int32_t midiVolume;
  int32_t mp3Volume;
  int32_t modVolume;
};
struct MUGEN_CONFIG_MISC_ {
  int32_t playerCache;
  uint32_t precache;
  uint32_t bufferedRead;
  uint32_t unloadSystem;
  uint32_t pauseOnDefocus;
};
struct MUGEN_CONFIG_ARCADE_ {
  uint32_t ai_randomColor;
  uint32_t ai_cheat;
  int32_t arcade_AIramp_start_match;
  int32_t arcade_AIramp_start_diff;
  int32_t arcade_AIramp_end_match;
  int32_t arcade_AIramp_end_diff;
  int32_t team_AIramp_start_match;
  int32_t team_AIramp_start_diff;
  int32_t team_AIramp_end_match;
  int32_t team_AIramp_end_diff;
  int32_t survival_AIramp_start_match;
  int32_t survival_AIramp_start_diff;
  int32_t survival_AIramp_end_match;
  int32_t survival_AIramp_end_diff;
};
struct MUGEN_CONFIG_INPUT_ {
  uint32_t p1_useKeyboard;
  uint32_t p2_useKeyboard;
  uint32_t p1_joystick_enable;
  uint32_t p2_joystick_enable;
  uint32_t p1_joystick_type;
  uint32_t p2_joystick_type;
  uint32_t forceFeedback;
  undefined4 psxDelay;
};
struct MUGEN_CONFIG_KEYS_ {
  undefined4 _unknown_1;
  DIRECT_INPUT_KEYCODE jump;
  DIRECT_INPUT_KEYCODE right;
  DIRECT_INPUT_KEYCODE crouch;
  DIRECT_INPUT_KEYCODE left;
  DIRECT_INPUT_KEYCODE a;
  DIRECT_INPUT_KEYCODE b;
  DIRECT_INPUT_KEYCODE c;
  DIRECT_INPUT_KEYCODE x;
  DIRECT_INPUT_KEYCODE y;
  DIRECT_INPUT_KEYCODE z;
  DIRECT_INPUT_KEYCODE start;
  undefined4 _unknown_2;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MUGEN_FIGHT_LIFEBAR_ {
  int32_t p1_posX;
  int32_t p1_posY;
  int32_t p1_rangeX;
  int32_t p1_rangeY;
  undefined4 _unknown_1;
  MUGEN_SYSTEM_VIEW_ITEM p1_bg0;
  MUGEN_SYSTEM_VIEW_ITEM p1_bg1;
  MUGEN_SYSTEM_VIEW_ITEM p1_bg2;
  MUGEN_SYSTEM_VIEW_ITEM p1_mid;
  MUGEN_SYSTEM_VIEW_ITEM p1_front;
  int32_t p2_posX;
  int32_t p2_posY;
  int32_t p2_rangeX;
  int32_t p2_rangeY;
  undefined4 _unknown_2;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg0;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg1;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg2;
  MUGEN_SYSTEM_VIEW_ITEM p2_mid;
  MUGEN_SYSTEM_VIEW_ITEM p2_front;
};
struct MUGEN_FIGHT_SIMUL_LIFEBAR_ {
  int32_t p1_posX;
  int32_t p1_posY;
  int32_t p1_rangeX;
  int32_t p1_rangeY;
  undefined4 _unknown_1;
  MUGEN_SYSTEM_VIEW_ITEM p1_bg0;
  MUGEN_SYSTEM_VIEW_ITEM p1_bg1;
  MUGEN_SYSTEM_VIEW_ITEM p1_bg2;
  MUGEN_SYSTEM_VIEW_ITEM p1_mid;
  MUGEN_SYSTEM_VIEW_ITEM p1_front;
  int32_t p2_posX;
  int32_t p2_posY;
  int32_t p2_rangeX;
  int32_t p2_rangeY;
  undefined4 _unknown_2;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg0;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg1;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg2;
  MUGEN_SYSTEM_VIEW_ITEM p2_mid;
  MUGEN_SYSTEM_VIEW_ITEM p2_front;
  int32_t p3_posX;
  int32_t p3_posY;
  int32_t p3_rangeX;
  int32_t p3_rangeY;
  undefined4 _unknown_3;
  MUGEN_SYSTEM_VIEW_ITEM p3_bg0;
  MUGEN_SYSTEM_VIEW_ITEM p3_bg1;
  MUGEN_SYSTEM_VIEW_ITEM p3_bg2;
  MUGEN_SYSTEM_VIEW_ITEM p3_mid;
  MUGEN_SYSTEM_VIEW_ITEM p3_front;
  int32_t p4_posX;
  int32_t p4_posY;
  int32_t p4_rangeX;
  int32_t p4_rangeY;
  undefined4 _unknown_4;
  MUGEN_SYSTEM_VIEW_ITEM p4_bg0;
  MUGEN_SYSTEM_VIEW_ITEM p4_bg1;
  MUGEN_SYSTEM_VIEW_ITEM p4_bg2;
  MUGEN_SYSTEM_VIEW_ITEM p4_mid;
  MUGEN_SYSTEM_VIEW_ITEM p4_front;
};
struct MUGEN_FIGHT_POWERBAR_ {
  int32_t p1_posX;
  int32_t p1_posY;
  int32_t p1_rangeX;
  int32_t p1_rangeY;
  undefined4 _unknown_1;
  MUGEN_SYSTEM_VIEW_ITEM p1_bg0;
  MUGEN_SYSTEM_VIEW_ITEM p1_bg1;
  MUGEN_SYSTEM_VIEW_ITEM p1_bg2;
  MUGEN_SYSTEM_VIEW_ITEM p1_mid;
  MUGEN_SYSTEM_VIEW_ITEM p1_front;
  int32_t p2_posX;
  int32_t p2_posY;
  int32_t p2_rangeX;
  int32_t p2_rangeY;
  undefined4 _unknown_2;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg0;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg1;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg2;
  MUGEN_SYSTEM_VIEW_ITEM p2_mid;
  MUGEN_SYSTEM_VIEW_ITEM p2_front;
  MUGEN_SYSTEM_VIEW_ITEM p1_counterText;
  MUGEN_SYSTEM_VIEW_ITEM p2_counterText;
  int32_t level0_snd_groupNo;
  int32_t level1_snd_groupNo;
  int32_t level2_snd_groupNo;
  int32_t level3_snd_groupNo;
  int32_t level4_snd_groupNo;
  int32_t level5_snd_groupNo;
  int32_t level6_snd_groupNo;
  int32_t level7_snd_groupNo;
  int32_t level8_snd_groupNo;
  int32_t level9_snd_groupNo;
  int32_t level0_snd_itemNo;
  int32_t level1_snd_itemNo;
  int32_t level2_snd_itemNo;
  int32_t level3_snd_itemNo;
  int32_t level4_snd_itemNo;
  int32_t level5_snd_itemNo;
  int32_t level6_snd_itemNo;
  int32_t level7_snd_itemNo;
  int32_t level8_snd_itemNo;
  int32_t level9_snd_itemNo;
};
struct MUGEN_FIGHT_FACE_ {
  MUGEN_SYSTEM_VIEW_ITEM p1_bg;
  MUGEN_SYSTEM_VIEW_ITEM p1_face;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg;
  MUGEN_SYSTEM_VIEW_ITEM p2_face;
  undefined1 _unknown_1[432]; /* p3_bg?, p3_face?, p4_bg?, p4_face? */
  int32_t p1_posX;
  int32_t p2_posX;
  undefined4 _unknown_2; /* p3_posX? */
  undefined4 _unknown_3; /* p4_posX? */
  int32_t p1_posY;
  int32_t p2_posY;
  undefined4 _unknown_4; /* p3_posY? */
  undefined4 _unknown_5; /* p4_posY? */
  int32_t p1_face_facing;
  int32_t p2_face_facing;
  undefined4 _unknown_6; /* p3_face_facing? */
  undefined4 _unknown_7; /* p4_face_facing? */
};
struct MUGEN_FIGHT_SIMUL_FACE_ {
  MUGEN_SYSTEM_VIEW_ITEM p1_bg;
  MUGEN_SYSTEM_VIEW_ITEM p1_face;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg;
  MUGEN_SYSTEM_VIEW_ITEM p2_face;
  MUGEN_SYSTEM_VIEW_ITEM p3_bg;
  MUGEN_SYSTEM_VIEW_ITEM p3_face;
  MUGEN_SYSTEM_VIEW_ITEM p4_bg;
  MUGEN_SYSTEM_VIEW_ITEM p4_face;
  int32_t p1_posX;
  int32_t p2_posX;
  int32_t p3_posX;
  int32_t p4_posX;
  int32_t p1_posY;
  int32_t p2_posY;
  int32_t p3_posY;
  int32_t p4_posY;
  int32_t p1_face_facing;
  int32_t p2_face_facing;
  int32_t p3_face_facing;
  int32_t p4_face_facing;
};
struct MUGEN_FIGHT_TURNS_FACE_ {
  MUGEN_FIGHT_FACE face;
  MUGEN_SYSTEM_VIEW_ITEM p1_teamMate_bg;
  MUGEN_SYSTEM_VIEW_ITEM p1_teamMate_face;
  MUGEN_SYSTEM_VIEW_ITEM p1_teamMate_ko;
  int32_t p1_teamMate_posX;
  int32_t p1_teamMate_posY;
  undefined4 _unknown_1;
  int32_t p1_teamMate_spacingX;
  int32_t p1_teamMate_spacingY;
  MUGEN_SYSTEM_VIEW_ITEM p2_teamMate_bg;
  MUGEN_SYSTEM_VIEW_ITEM p2_teamMate_face;
  MUGEN_SYSTEM_VIEW_ITEM p2_teamMate_ko;
  int32_t p2_teamMate_posX;
  int32_t p2_teamMate_posY;
  undefined4 _unknown_2;
  int32_t p2_teamMate_spacingX;
  int32_t p2_teamMate_spacingY;
};
struct MUGEN_FIGHT_NAME_ {
  MUGEN_SYSTEM_VIEW_ITEM p1_bg;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg;
  undefined1 _unknown_1[216]; /* p3_bg?, p4_bg?*/
  MUGEN_SYSTEM_VIEW_ITEM p1_name;
  MUGEN_SYSTEM_VIEW_ITEM p2_name;
  undefined1 _unknown_2[216]; /* p3_name?, p4_name? */
  int32_t p1_posX;
  int32_t p2_posX;
  undefined4 _unknown_3; /* p3_posX? */
  undefined4 _unknown_4; /* p4_posX? */
  int32_t p1_posY;
  int32_t p2_posY;
  undefined4 _unknown_5; /* p3_posY? */
  undefined4 _unknown_6; /* p4_posY? */
};
struct MUGEN_FIGHT_SIMUL_NAME_ {
  MUGEN_SYSTEM_VIEW_ITEM p1_bg;
  MUGEN_SYSTEM_VIEW_ITEM p2_bg;
  MUGEN_SYSTEM_VIEW_ITEM p3_bg;
  MUGEN_SYSTEM_VIEW_ITEM p4_bg;
  MUGEN_SYSTEM_VIEW_ITEM p1_name;
  MUGEN_SYSTEM_VIEW_ITEM p2_name;
  MUGEN_SYSTEM_VIEW_ITEM p3_name;
  MUGEN_SYSTEM_VIEW_ITEM p4_name;
  int32_t p1_posX;
  int32_t p2_posX;
  int32_t p3_posX;
  int32_t p4_posX;
  int32_t p1_posY;
  int32_t p2_posY;
  int32_t p3_posY;
  int32_t p4_posY;
};
struct MUGEN_FIGHT_TIME_ {
  MUGEN_SYSTEM_VIEW_ITEM bg;
  MUGEN_SYSTEM_VIEW_ITEM counterText;
  int32_t posX;
  int32_t posY;
  int32_t framesPerCount;
};
struct MUGEN_FIGHT_COMBO_ {
  int32_t posX;
  int32_t posY;
  int32_t startX;
  int32_t displayTime;
  int32_t counter_font_fontNo;
  int32_t counter_font_fontBank;
  uint32_t counter_shake;
  int32_t text_font_fontNo;
  int32_t text_font_fontBank;
  int32_t text_offsetX;
  int32_t text_offsetY;
  char text_text[32];
};
struct MUGEN_FIGHT_ROUND_ {
  int32_t match_wins;
  int32_t match_maxDrawGames;
  int32_t start_waitTime;
  int32_t intro_time;
  int32_t posX;
  int32_t posY;
  MUGEN_SYSTEM_VIEW_ITEM round_defaultText;
  MUGEN_SYSTEM_VIEW_ITEM round_n_text[10]; /* all member of round_0_text is always zero */
  int32_t round_time;
  int32_t round_sndTime;
  int32_t round_n_snd_groupNo[10]; /* round_0_snd_groupNo is always zero */
  int32_t round_n_snd_itemNo[10];  /* round_0_snd_itemNo is always zero */
  MUGEN_SYSTEM_VIEW_ITEM fight_anim;
  int32_t fight_time;
  int32_t fight_sndTime;
  MUGEN_SOUND fight_snd;
  MUGEN_SYSTEM_VIEW_ITEM ko_anim;
  MUGEN_SYSTEM_VIEW_ITEM dko_text;
  MUGEN_SYSTEM_VIEW_ITEM to_text;
  undefined4 _unknown_1; /* ko_time? */
  int32_t ko_sndTime;
  MUGEN_SOUND ko_snd;
  MUGEN_SOUND dko_snd;
  MUGEN_SOUND to_snd;
  MUGEN_SYSTEM_VIEW_ITEM win_text;
  MUGEN_SYSTEM_VIEW_ITEM win2_text;
  MUGEN_SYSTEM_VIEW_ITEM draw_text;
  MUGEN_SOUND win_snd;
  MUGEN_SOUND win2_snd;
  MUGEN_SOUND draw_snd;
  int32_t win_time;
  int32_t ctrl_time;
  int32_t slow_time;
  int32_t over_waitTime;
  int32_t over_hitTime;
  int32_t over_winTime;
  int32_t over_time;
};
struct MUGEN_FIGHT_WINICON_ {
  MUGEN_SYSTEM_VIEW_ITEM p1_counter;
  MUGEN_SYSTEM_VIEW_ITEM p2_counter;
  MUGEN_SYSTEM_VIEW_ITEM p1_n;
  MUGEN_SYSTEM_VIEW_ITEM p1_s;
  MUGEN_SYSTEM_VIEW_ITEM p1_h;
  MUGEN_SYSTEM_VIEW_ITEM p1_c;
  MUGEN_SYSTEM_VIEW_ITEM p1_t;
  MUGEN_SYSTEM_VIEW_ITEM p1_throw;
  MUGEN_SYSTEM_VIEW_ITEM p1_suicide;
  MUGEN_SYSTEM_VIEW_ITEM p1_teamMate;
  MUGEN_SYSTEM_VIEW_ITEM p1_perfect;
  MUGEN_SYSTEM_VIEW_ITEM p2_n;
  MUGEN_SYSTEM_VIEW_ITEM p2_s;
  MUGEN_SYSTEM_VIEW_ITEM p2_h;
  MUGEN_SYSTEM_VIEW_ITEM p2_c;
  MUGEN_SYSTEM_VIEW_ITEM p2_t;
  MUGEN_SYSTEM_VIEW_ITEM p2_throw;
  MUGEN_SYSTEM_VIEW_ITEM p2_suicide;
  MUGEN_SYSTEM_VIEW_ITEM p2_teamMate;
  MUGEN_SYSTEM_VIEW_ITEM p2_perfect;
  int32_t p1_posX;
  int32_t p2_posX;
  int32_t p1_posY;
  int32_t p2_posY;
  int32_t p1_iconOffsetX;
  int32_t p2_iconOffsetX;
  int32_t p1_iconOffsetY;
  int32_t p2_iconOffsetY;
  int32_t useIconUpTo;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MUGEN_SYSTEM_TITLE_INFO_ {
  int32_t fadeIn_time;
  int32_t fadeOut_time;
  MUGEN_SOUND cursor_move_snd;
  MUGEN_SOUND cursor_done_snd;
  MUGEN_SOUND cancel_snd;
  int32_t menu_posX;
  int32_t menu_posY;
  MUGEN_FONT menu_item_font;
  MUGEN_FONT menu_item_active_font;
  int32_t menu_item_spacing_x;
  int32_t menu_item_spacing_y;
  char menu_itemName_arcade[32];
  char menu_itemName_versus[32];
  char menu_itemName_teamArcade[32];
  char menu_itemName_teamVersus[32];
  char menu_itemName_teamCoop[32];
  char menu_itemName_survival[32];
  char menu_itemName_survivalCoop[32];
  char menu_itemName_training[32];
  char menu_itemName_watch[32];
  char menu_itemName_options[32];
  char menu_itemName_exit[32];
  int32_t menu_window_margins_y_upper;
  int32_t menu_windows_margins_y_bottom;
  int32_t menu_window_visibleItems;
  uint32_t menu_boxCursor_visible;
  int32_t menu_boxCursor_coords_x_left;
  int32_t menu_boxCursor_coords_y_upper;
  int32_t menu_boxCursor_coords_x_right;
  int32_t menu_boxCursor_coords_y_bottom;
};
struct MUGEN_SYSTEM_SELECTINFO_ {
  int32_t fadeIn_time;
  int32_t fadeOut_time;
  int32_t posX;
  int32_t posY;
  int32_t rows;
  int32_t columns;
  int32_t cell_spacing;
  int32_t cell_sizeX;
  int32_t cell_sizeY;
  uint32_t wrapping;
  uint32_t showEmptyBoxes;
  uint32_t moveOverEmptyBoxes;
  float portrait_scaleX;
  float portrait_scaleY;
  int32_t portrait_offsetX;
  int32_t portrait_offsetY;
};
struct MUGEN_SYSTEM_SELECTINFO2_ {
  uint32_t p2_cursor_blink;
  int32_t p1_cursor_move_snd_groupNo;
  int32_t p2_cursor_move_snd_groupNo;
  int32_t p1_cursor_move_snd_itemNo;
  int32_t p2_cursor_move_snd_itemNo;
  int32_t p1_cursor_done_snd_groupNo;
  int32_t p2_cursor_done_snd_groupNo;
  int32_t p1_cursor_done_snd_itemNo;
  int32_t p2_cursor_done_snd_itemNo;
  int32_t p1_random_move_snd_groupNo;
  int32_t p2_random_move_snd_groupNo;
  int32_t p1_random_move_snd_itemNo;
  int32_t p2_random_move_snd_itemNo;
  uint32_t random_move_snd_cancel;
  MUGEN_SOUND stage_move_snd;
  MUGEN_SOUND stage_done_snd;
  MUGEN_SOUND cancel_snd;
  int32_t title_offsetX;
  int32_t title_offsetY;
  MUGEN_FONT title_font;
  MUGEN_SYSTEM_VIEW_ITEM cell_bg;
  MUGEN_SYSTEM_VIEW_ITEM cell_random;
  int32_t cell_random_switchTime;
  MUGEN_SYSTEM_VIEW_ITEM p1_cursor_active;
  MUGEN_SYSTEM_VIEW_ITEM p2_cursor_active;
  MUGEN_SYSTEM_VIEW_ITEM p1_cursor_done;
  MUGEN_SYSTEM_VIEW_ITEM p2_cursor_done;
  int32_t stage_posX;
  int32_t stage_posY;
  int32_t stage_active_font_fontNo;
  int32_t stage_active2_font_fontNo;
  int32_t stage_done_font_fontNo;
  int32_t stage_active_font_colorsNo;
  int32_t stage_active2_font_colorsNo;
  int32_t stage_done_font_colorsNo;
  int32_t stage_active_font_alignment;
  int32_t p1_face_offsetX;
  int32_t p1_face_offsetY;
  int32_t p1_face_facing;
  float p1_face_scaleX;
  float p1_face_scaleY;
  MUGEN_FONT p1_name_font;
  int32_t p1_name_offsetX;
  int32_t p1_name_offsetY;
  int32_t p2_face_offsetX;
  int32_t p2_face_offsetY;
  int32_t p2_face_facing;
  float p2_face_scaleX;
  float p2_face_scaleY;
  MUGEN_FONT p2_name_font;
  int32_t p2_name_offsetX;
  int32_t p2_name_offsetY;
  uint32_t teamMenu_move_wrapping;
  int32_t p1_teamMenu_posX;
  int32_t p1_teamMenu_posY;
  MUGEN_SYSTEM_VIEW_ITEM p1_teamMenu_bg;
  MUGEN_SYSTEM_VIEW_ITEM p1_teamMenu_selfTitle;
  MUGEN_SYSTEM_VIEW_ITEM p1_teamMenu_enemyTitle;
  MUGEN_SOUND p1_teamMenu_move_snd;
  MUGEN_SOUND p1_teamMenu_value_snd;
  MUGEN_SOUND p1_teamMenu_done_snd;
  int32_t p1_teamMenu_item_offsetX;
  int32_t p1_teamMenu_item_offsetY;
  int32_t p1_teamMenu_item_fonr_fontNo;
  int32_t p1_teamMenu_item_active_font_fontNo;
  int32_t p1_teamMenu_item_active2_font_fontNo;
  int32_t p1_teamMenu_item_font_colorsNo;
  int32_t p1_teamMenu_iitem_active_font_colorsNo;
  int32_t p1_teamMenu_item_active2_font_colors;
  int32_t p1_teamMenu_item_font_alignment;
  int32_t p1_teamMenu_item_spacingX;
  int32_t p1_teamMenu_item_spacingY;
  MUGEN_SYSTEM_VIEW_ITEM p1_teamMenu_item_cursor;
  MUGEN_SYSTEM_VIEW_ITEM p1_teamMenu_value_icon;
  int32_t p1_teamMenu_value_spacingX;
  int32_t p1_teamMenu_value_spacingY;
  MUGEN_SYSTEM_VIEW_ITEM p1_teamMenu_value_empty_icon;
  undefined4 _unknown_1;
  undefined4 _unknown_2;
  int32_t p2_teamMenu_posX;
  int32_t p2_teamMenu_posY;
  MUGEN_SYSTEM_VIEW_ITEM p2_teamMenu_bg;
  MUGEN_SYSTEM_VIEW_ITEM p2_teamMenu_selfTitle;
  MUGEN_SYSTEM_VIEW_ITEM p2_teamMenu_enemyTitle;
  MUGEN_SOUND p2_teamMenu_move_snd;
  MUGEN_SOUND p2_teamMenu_value_snd;
  MUGEN_SOUND p2_teamMenu_done_snd;
  int32_t p2_teamMenu_item_offsetX;
  int32_t p2_teamMenu_item_offsetY;
  int32_t p2_teamMenu_item_font_fontNo;
  int32_t p2_teamMenu_item_active_font_fontNo;
  int32_t p2_teamMenu_item_active2_font_fontNo;
  int32_t p2_teamMenu_item_font_colorsNo;
  int32_t p2_teamMenu_item_active_font_colorsNo;
  int32_t p2_teamMenu_item_active2_font_colorsNo;
  int32_t p2_teamMenu_item_font_alignment;
  int32_t p2_teamMenu_item_spacingX;
  int32_t p2_teamMenu_item_spacingY;
  MUGEN_SYSTEM_VIEW_ITEM p2_teamMenu_item_cursor;
  MUGEN_SYSTEM_VIEW_ITEM p2_teamMenu_value_icon;
  int32_t p2_teamMenu_value_spacingX;
  int32_t p2_teamMenu_value_spacingY;
  MUGEN_SYSTEM_VIEW_ITEM p2_teamMenu_value_empty_icon;
  undefined4 _unknown_3;
  undefined4 _unknown_4;
};
struct MUGEN_SYSTEM_VS_SCREEN_ {
  int32_t time;
  int32_t fadeIn_time;
  int32_t fadeOut_time;
  int32_t p1_posX;
  int32_t p1_posY;
  MUGEN_FONT p1_name_font;
  int32_t p1_name_posX;
  int32_t p1_name_posY;
  int32_t p1_facing;
  float p1_scaleX;
  float p1_scaleY;
  int32_t p2_posX;
  int32_t p2_posY;
  MUGEN_FONT p2_name_font;
  int32_t p2_name_posX;
  int32_t p2_name_posY;
  int32_t p2_facing;
  float p2_scaleX;
  float p2_scaleY;
};
struct MUGEN_SYSTEM_DEMO_MODE_ {
  int32_t intro_waitCycles;
  int32_t title_waitTime;
  uint32_t select_enabled;
  uint32_t select_vsScreen_enabled;
  int32_t fight_endTime;
  uint32_t fight_playBGM;
  uint32_t fight_bars_display;
  uint32_t debugInfo;
};
struct MUGEN_SYSTEM_CONTINUE_SCREEN_ {
  uint32_t enabled;
  char storyBoard[512];
};
struct MUGEN_SYSTEM_GAME_OVER_SCREEN_ {
  uint32_t enabled;
  char storyBoard[512];
};
struct MUGEN_SYSTEM_WINSCREEN_ {
  uint32_t enabled;
  MUGEN_SYSTEM_VIEW_ITEM winText;
  int32_t pose_time;
  int32_t fadeIn_time;
  int32_t fadeOut_time;
};
struct MUGEN_SYSTEM_DEFAULT_ENDING_ {
  uint32_t enabled;
  char storyBoard[512];
};
struct MUGEN_SYSTEM_END_CREDITS_ {
  uint32_t enabled;
  char storyBoard[512];
};
struct MUGEN_SYSTEM_SURVIVAL_RESULTS_SCREEN_ {
  uint32_t enabled;
  MUGEN_SYSTEM_VIEW_ITEM winsText;
  int32_t show_time;
  int32_t fadeIn_time;
  int32_t fadeOut_time;
  int32_t roundsToWin;
};
struct MUGEN_SYSTEM_OPTION_INFO_ {
  MUGEN_SOUND cursor_move_snd;
  MUGEN_SOUND cursor_done_snd;
  MUGEN_SOUND cancel_snd;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MUGEN_STAGE_CAMERA_ {
  int32_t startX;
  int32_t startY;
  int32_t boundLeft;
  int32_t boundRight;
  int32_t boundHigh;
  int32_t boundLow;
  float verticalFollow;
  int32_t tension;
  int32_t floorTension;
};
struct MUGEN_STAGE_PLAYERINFO_ {
  int32_t p1StartX;
  int32_t p2StartX;
  int32_t p3StartX;
  int32_t p4StartX;
  int32_t p1StartY;
  int32_t p2StartY;
  int32_t p3StartY;
  int32_t p4StartY;
  int32_t p1StartZ;
  int32_t p2StartZ;
  int32_t p3StartZ;
  int32_t p4StartZ;
  int32_t p1Facing;
  int32_t p2Facing;
  int32_t p3Facing;
  int32_t p4Facing;
  int32_t leftBound;
  int32_t rightBound;
  int32_t topBound;
  int32_t botBound;
};
struct MUGEN_STAGE_SCALING_ {
  int32_t topZ;
  int32_t botZ;
  float topScale;
  float botScale;
};
struct MUGEN_STAGE_BOUND_ {
  int32_t screenLeft;
  int32_t screenRight;
};
struct MUGEN_STAGE_SHADOW_ {
  int32_t intensity;
  uint32_t color;
  float yScale;
  int32_t fade_range_high;
  int32_t fade_range_middle;
};
struct MUGEN_STAGE_REFLECTION_ {
  int32_t intensity;
};
struct MUGEN_STAGE_MUSIC_ {
  uint32_t musicFormatType;
  MIDI* midi;
  JGMOD* mod;
  uint32_t cdTrackNo;
  undefined4 _unknown_1;
  undefined4 _unknown_2;
  int32_t bgVolume;
  undefined4 _unknown_3; /* related to CD? */
  undefined4 _unknown_4;
  undefined4 _unknown_5;
  char bgMusic[512];
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MUGEN_VERSION_DATA_ {
  int32_t month;
  int32_t day;
  int32_t year;
};
struct MUGEN_REGISTERED_CHARS_ {
  int32_t useCount;
  undefined4 _unknown_1;
  MUGEN_PLAYER_INFO* pInfo;
  char _unknown_2[512];
  char defFilename[512];
  char defDirname[512];
  char stagePath[512];
  char bgmPath[512];
  int32_t order;
  int32_t selectIdx;
  uint32_t palNos;
  int32_t pal_defaults[4];
  undefined4 _unknown_3;
  char introPath[512];
  char endingPath[512];
  uint32_t leftPalNos;
};
struct MUGEN_SELECT_OPTION_ {
  int32_t arcade_maxMatches[10];
  int32_t team_maxMatches[10];
};
struct MUGEN_REGISTERED_PORTRAITS_ {
  int32_t charsIdx; /* -1: Blank, -2: RandomSelect */
  char name[48];
  char defFilename[512];
  char defDirname[512];
  MUGEN_SFF_INFO_EX* portraitsSprites;
};
struct MUGEN_STAGE_LIST_ {
  char path[512];
  char name[80];
  uint32_t flag;
};
struct MUGEN_TURN_CHARSET_ {
  uint32_t isSimul;
  undefined4 _unknown_1;
  int32_t simulEntries;       /* simul->2, otherwise->1 */
  uint32_t firstPlayerSlotID; /* set 0 if there is no p1 */
  uint32_t firstPlayerCharIndex;
  uint32_t firstPlayerPalNo;
  undefined4 _unknown_2;
  uint32_t firstPlayerExist;
  uint32_t secondPlayerSlotID;
  uint32_t secondPlayerCharIndex;
  uint32_t secondPlayerPalNo;
  undefined4 _unknown_3;
  uint32_t secondPlayerExist;
  undefined4 _unknown_4; /* thirdPlayerSlotID? */
  undefined4 _unknown_5; /* thirdPlayerCharIndex? */
  undefined4 _unknown_6; /* thirdPlayerPalNo? */
  undefined4 _unknown_7;
  undefined4 _unknown_8;  /* thirdPlayerExist? */
  undefined4 _unknown_9;  /* fourthPlayerSlotID? */
  undefined4 _unknown_10; /* fourthPlayerCharIndex? */
  undefined4 _unknown_11; /* fourthPlayerPalNo? */
  undefined4 _unknown_12;
  undefined4 _unknown_13; /* fourthPlayerExist? */
};
struct MUGEN_ASSERT_SPECIAL_FLAGS_ {
  uint8_t intro;
  uint8_t roundNotOver;
  uint8_t noKO;
  uint8_t noKOSnd;
  uint8_t noKOSlow;
  uint8_t noKOMusic;
  uint8_t globalNoShadow;
  uint8_t timerFreeze;
  uint8_t noBarDisplay;
  uint8_t noBG;
  uint8_t noFG;
  undefined1 _padding;
};
struct MUGEN_INT_CIRC_BUF_ {
  int32_t* buf;
  int32_t requiredIdx;
  int32_t currentIdx;
  int32_t length;
};
struct MUGEN_PAL_GROUP_ {
  int32_t _unknown[5];
};
struct MUGEN_SC_PAUSE_ {
  MUGEN_PAL_GROUP palGrp;
  uint32_t darken;
  int32_t time;
  uint32_t pauseBG;
  int32_t endCmdBufTime;
};
struct MUGEN_COMBO_CNT_ {
  int32_t displayTime;
  int32_t internalComboCnt;
  undefined4 _unknown_1;
  int32_t comboCnt;
  int32_t posX;
  undefined4 _unknown_2;
};
struct MUGEN_CLIPBOARD_ {
  char** messages; /* Ring buffer */
  char* _unknown;
  int32_t charsPerLine;
  int32_t lines;
  int32_t firstMessageIndex;
  int32_t lastMessageIndex;
};

struct MUGEN_GAME_VAR_ {
  char currentDirName[512];
  char currentDirPath[512];
  undefined4 _unknown_1;
  undefined4 _unknown_2;
  MUGEN_VERSION_DATA date;
  char stageDefPath[512];
  char _unknown_3[512];
  MUGEN_SYSTEM_TITLE_INFO titleInfo;
  undefined4 _unknown_4;
  undefined4 _unknown_5;
  MUGEN_SYSTEM_OPTION_INFO optionInfo;
  uint32_t resetBG;
  MUGEN_STAGE_CAMERA camera;
  MUGEN_STAGE_PLAYERINFO playerInfo;
  uint32_t autoTurn;
  MUGEN_STAGE_SCALING scaling;
  MUGEN_STAGE_BOUND bound;
  MUGEN_STAGE_SHADOW shadow;
  MUGEN_STAGE_REFLECTION reflection;
  MUGEN_STAGE_MUSIC music;
  MUGEN_REGISTERED_CHARS* chars;
  int32_t charsCnt;
  int32_t currentPlayerCacheCnt;
  int32_t maxCharsCnt;
  int32_t* arcadeEnemyIndexList;
  undefined4 _unknown_6;
  undefined4 _unknown_7;
  undefined4 _unknown_8;
  MUGEN_SELECT_OPTION orders;
  uint32_t needPrecaching; /* 1: do pre-loading, 0: do nothing */
  HANDLE hCharLoadMutex;
  undefined4 _unknown_9;
  uint32_t charLoadStatus;
  undefined4 _unknown_10;
  undefined4 _unknown_11;
  int32_t selectCharIndex;
  undefined4 _unknown_12;
  undefined4 _unknown_13;
  undefined4 _unknown_14;
  undefined4 _unknown_15;
  char select[512];
  MUGEN_SYSTEM_SELECTINFO selectInfo;
  int32_t p1Cursor_startCellX;
  int32_t p2Cursor_startCellX;
  int32_t p1Cursor_startCellY;
  int32_t p2Cursor_startCellY;
  int32_t p1_first_char_cellX;
  int32_t p1_second_char_cellX;
  int32_t p1_third_char_cellX;
  int32_t p1_fourth_char_cellX;
  int32_t p2_first_char_cellX;
  int32_t p2_second_char_cellX;
  int32_t p2_third_char_cellX;
  int32_t p2_fourth_char_cellX;
  int32_t p1_first_char_cellY;
  int32_t p1_second_char_cellY;
  int32_t p1_third_char_cellY;
  int32_t p1_fourth_char_cellY;
  int32_t p2_first_char_cellY;
  int32_t p2_second_char_cellY;
  int32_t p2_third_char_cellY;
  int32_t p2_fourth_char_cellY;
  MUGEN_SYSTEM_SELECTINFO2 selectInfo2;
  MUGEN_REGISTERED_PORTRAITS* portraits;
  char logo_storyBoard[512];
  char intro_storyBoard[512];
  undefined4 _unknown_16;
  MUGEN_SYSTEM_END_CREDITS end_credits;
  MUGEN_SYSTEM_DEFAULT_ENDING default_ending;
  MUGEN_SYSTEM_WINSCREEN winScreen;
  MUGEN_SYSTEM_SURVIVAL_RESULTS_SCREEN survivdedResultsScreen;
  MUGEN_SYSTEM_CONTINUE_SCREEN continueScreen;
  MUGEN_SYSTEM_GAME_OVER_SCREEN gameOverScreen;
  MUGEN_SYSTEM_VS_SCREEN vsScreen;
  MUGEN_STAGE_LIST* stages;
  int32_t stageCnt;
  uint32_t matchType; /* 0: Arcade/Versus, 1: Survival, 2: Watch, 3: Training */
  undefined4 _unknown_17;
  undefined4 _unknown_18;
  undefined4 _unknown_19;
  undefined4 _unknown_20;
  uint32_t isHomeTeamRight;
  uint32_t isSurvival;
  uint32_t gameMode; /* 0: Arcade, 1: Versus, 2: Team Arcade, 3: Team Versus, 4: Team CO-OP, 5: Survival, 6: Survival CO-OP, 7: Training, 8: Watch */
  uint32_t isP2FirstSelect;
  uint32_t currentScreen; /* 0: gamemode select, 4: fighting, 6: arcade continue/survival result, 7: char select */
  undefined4 _unknown_21;
  int32_t p1TotalTurns; /* turns: num of chars, other: 1 */
  int32_t p1TotalChars;
  MUGEN_TURN_CHARSET p1Turns[4];
  undefined4 _unknown_22[1600];
  int32_t _unknown_23;
  float _unknown_24;
  float _unknown_25;
  undefined4 _unknown_26;
  float p1LifeMul;
  int32_t p1WinsGoal;
  undefined4 _unknown_27;
  float _unknown_28;
  undefined4 _unknown_29;
  int32_t p2TotalTurns;
  int32_t p2TotalChars;
  MUGEN_TURN_CHARSET p2Turns[4];
  undefined4 _unknown_30[1600];
  int32_t _unknown_31;
  float _unknown_32;
  float _unknown_33;
  undefined4 _unknown_34;
  float p2LifeMul;
  int32_t p2WinsGoal;
  undefined4 _unknown_35;
  float _unknown_36;
  MUGEN_TURN_CHARSET p1CurrentTurn;
  MUGEN_TURN_CHARSET p2CurrentTurn;
  undefined4 _unknown_37;
  undefined4 _unknown_38;
  MUGEN_SFF_INFO_EX* screenBuffer1;
  MUGEN_SFF_INFO_EX* _unknown_40;
  MUGEN_SFF_INFO_EX* screenBuffer2;
  MUGEN_SFF_INFO_EX* currentScreenBuffer;
  void* _unknown_43;
  void* _unknown_44;
  MUGEN_ANIM_INFO_EX* persistentAnimArray;
  MUGEN_SFF_INFO_EX* prioritySpritesLayer1;
  void* palGroupArray;
  MUGEN_AFTERIMAGE_INFO* afterImages;
  int32_t zOffset;
  int32_t currentZOffset;
  int32_t zOffsetLink;
  uint32_t vRet;
  uint32_t envColor_under;
  uint32_t envColor_value;
  int32_t envColor_time;
  MUGEN_SFF_INFO_EX* fightfx_sff;
  MUGEN_ANIM_INFO_EX* fightfx_anim;
  MUGEN_SFF_INFO_EX* fight_sff;
  MUGEN_ANIM_INFO_EX* fight_anim;
  void* _unknown_48;
  void* _unknown_49;
  void* _unknown_50;
  void* _unknown_51;
  void* _unknown_52;
  void* _unknown_53;
  void* _unknown_54;
  void* _unknown_55;
  void* _unknown_56;
  void* _unknown_57;
  MUGEN_SND_INFO** fight_snd;
  MUGEN_SND_INFO** common_snd;
  MUGEN_FIGHT_LIFEBAR lifebar;
  MUGEN_FIGHT_SIMUL_LIFEBAR simulLifebar;
  MUGEN_FIGHT_TURNS_LIFEBAR turnsLifebar;
  MUGEN_FIGHT_POWERBAR powerBar;
  MUGEN_FIGHT_FACE face;
  MUGEN_FIGHT_SIMUL_FACE simulFace;
  MUGEN_FIGHT_TURNS_FACE turnsFace;
  MUGEN_FIGHT_NAME name;
  MUGEN_FIGHT_SIMUL_NAME simulName;
  MUGEN_FIGHT_TURNS_NAME turnsName;
  MUGEN_FIGHT_TIME time;
  MUGEN_FIGHT_COMBO combo;
  MUGEN_FIGHT_ROUND round;
  MUGEN_FIGHT_WINICON winIcon;
  undefined4 _unknown_58;
  undefined4 _unknown_59;
  undefined4 _unknown_60;
  undefined4 _unknown_61;
  undefined4 _unknown_62;
  undefined4 _unknown_63;
  undefined4 _unknown_64;
  undefined4 _unknown_65;
  undefined4 _unknown_66;
  MUGEN_EXPLODS_INFO* explods;
  MUGEN_EXPLODS_INFO* sysExplods;
  char motif_basename[512];
  char motif_dirname[512];
  MUGEN_SFF_INFO_EX* system_sff;
  char system_sff_path[512];
  MUGEN_SND_INFO** system_snd;
  char system_snd_path[512];
  MUGEN_ANIM_INFO_EX* system_anim;
  void* _unknown_67;
  void* _unknown_68;
  void* _unknown_69;
  void* _unknown_70;
  void* _unknown_71;
  void* _unknown_72;
  void* _unknown_73;
  void* _unknown_74;
  void* _unknown_75;
  void* _unknown_76;
  void* _unknown_77; /* system_background? */
  void* _unknown_78; /* system_background? */
  void* _unknown_79; /* system_background? */
  void* _unknown_80; /* system_background? */
  char title_bgm_path[512];
  uint32_t title_bgm_loop;
  char vs_bgm_path[512];
  uint32_t vs_bgm_loop;
  char select_bgm_path[512];
  uint32_t select_bgm_loop;
  void* stage_background;
  MUGEN_PAL_FX bgPalFX;
  MUGEN_PAL_FX allPalFX;
  MUGEN_CONFIG_SOUND_WIN2 soundWin2;
  undefined4 _unknown_81;
  undefined4 _unknown_82;
  undefined4 _unknown_83;
  undefined4 _unknown_84;
  undefined4 _unknown_85;
  undefined4 _unknown_86;
  undefined field266_0xb1ec[512];
  undefined4 _unknown_87;
  undefined4 _unknown_88;
  undefined4 _unknown_89;
  undefined4 _unknown_90;
  int32_t gameTime;
  int32_t skipFrame;
  int32_t skipCnt;
  uint32_t skip;
  undefined4 _unknown_91;
  uint32_t pause;
  int32_t rand_seed;
  uint32_t isLifeSaving;
  uint32_t isScreenFading;
  int32_t screenFading;
  int32_t screenFadingGoal;
  float fStageAxisX;
  float fStageAxisY;
  int32_t iStageAxisX;
  int32_t iStageAxisY;
  float fStageAxisX2; /* Always same as the fStageAxisX? */
  float fStageAxisY2; /* Always same as the fStageAxisY? */
  int32_t shake_axisX;
  int32_t shake_axisY;
  MUGEN_ENV_SHAKE envShake;
  MUGEN_CONFIG_RULES rules;
  MUGEN_CONFIG_KEYS p1_keys;
  MUGEN_CONFIG_KEYS p2_keys;
  MUGEN_CONFIG_KEYS p1_keys_;
  MUGEN_CONFIG_KEYS p2_keys_;
  MUGEN_CONFIG_KEYS p1_joystick_keys;
  MUGEN_CONFIG_KEYS p2_joystick_keys;
  MUGEN_CONFIG_KEYS p1_joystick_win_keys;
  MUGEN_CONFIG_KEYS p2_joystick_win_keys;
  MUGEN_CONFIG_INPUT input;
  MUGEN_INT_CIRC_BUF intCircBuf;
  int32_t totalSlots; /* helperSlots + playerSlots */
  int32_t helperSlots;
  int32_t playerSlots;
  int32_t currentPlayers;
  MUGEN_PLAYER_INFO* playerInfoList[64]; /* [0] and [61]-[63] is always empty. */
  MUGEN_PLAYER* playerList[64];          /* [0] and [61]-[63] is always empty. */
  uint32_t isPlayerSlot[64];             /* [0] and [61]-[63] is always 0. */
  int32_t firstPlayerIndex;
  int32_t lastPlayerIndex;
  MUGEN_PLAYER* playerArray[65]; /* NULL terminated. */
  int32_t playerArrayLength;
  int32_t nextPlayerId;
  uint32_t isRunnableSlot[64];
  uint32_t isHelperSummoned;
  undefined4 _unknown_96;
  undefined4 _unknown_97;
  int32_t nextAttackNo;
  uint32_t takeScreenShot;
  MUGEN_ASSERT_SPECIAL_FLAGS assertSpecialFlags;
  undefined4 _unknown_98;
  undefined4 _unknown_99;
  uint32_t isPlayingDemo;
  MUGEN_SYSTEM_DEMO_MODE demoMode;
  int32_t demoElapsedTime;
  int32_t currentWaitCycles;
  uint32_t pauseType; /* 0: Pause, 1: SuperPause, -1: None */
  MUGEN_SC_PAUSE sc_pause;
  MUGEN_SC_PAUSE sc_superPause;
  int32_t roundNo;
  int32_t p1Wins;
  int32_t p2Wins;
  uint32_t isWinsAllotted;
  int32_t draws;
  int32_t leftKOSlowCnt;
  int32_t maxKOSlowTime;
  int32_t koSlowTime;
  int32_t introElapsedTime;    /* The elapsed time between rs1-rs2. */
  int32_t overWaitElapsedTime; /* The elapsed time between rs3-rs4. */
  int32_t over_time;
  int32_t roundState;
  uint32_t winTeam;
  uint32_t settledType; /* 1: KO, 2: DKO, 3: TO */
  int32_t currentStateElapsedTime;
  int32_t roundTimer;
  int32_t fightElapsedTime; /* The elapsed time between rs2-rs3. */
  uint32_t introSkipFlag;
  undefined4 _unknown_103;
  uint32_t p1WinIcons[10];
  uint32_t p2WinIcons[10];
  uint32_t p1PerfectIcons[10];
  uint32_t p2PerfectIcons[10];
  undefined4 _unknown_104;
  undefined4 _unknown_105;
  int32_t matchNo;
  int32_t totalMatchNo;
  undefined4 _unknown_106;
  uint32_t matchCancelFlag;
  MUGEN_COMBO_CNT p1ComboCnt;
  MUGEN_COMBO_CNT p2ComboCnt;
  MUGEN_CONFIG_VIDEO_WIN videoWin;
  MUGEN_CONFIG_SOUND_WIN soundWin;
  MUGEN_CONFIG_CONFIG config;
  MUGEN_CONFIG_MISC misc;
  MUGEN_CONFIG_ARCADE arcade;
  undefined4 _unknown_107;
  char _unknown_108[512];
  undefined4 _unknown_109[17];
  MUGEN_CONFIG_OPTIONS options;
  undefined4 _unknown_110[12];
  char startStage[512];
  undefined4 _unknown_111;
  undefined4 _unknown_112;
  undefined4 _unknown_113;
  undefined4 _unknown_114;
  undefined4 _unknown_115;
  undefined4 _unknown_116;
  undefined4 _unknown_117;
  undefined4 _unknown_118;
  undefined4 _unknown_119;
  uint32_t debug;
  uint32_t allowDebugMode;
  uint32_t allowDebugKeys;
  uint32_t clsnDebugMode; /* 0: None, 1: BoxFrame, 2: Rectangle */
  MUGEN_CLIPBOARD* warningClipboard;
  char errorMessage[1024];
  uint32_t speedUp;           /* Set 1 if ctrl+s */
  undefined4 _unknown_120;    /* If it is not 0, the speed set to 1. */
  uint32_t doRestartEffect;   /* It cause F4 effect. */
  uint32_t doReloadingEffect; /* If cause shift+F4 effect. */
  undefined4 _unknown_121;    /* If it is not 0, the speed set to 1. */
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

struct MUGEN_PLAYER_CONSTRAINTS_ {
  int32_t data_life;
  int32_t data_power;
  int32_t data_attack;
  int32_t size_attack_z_width_front;
  int32_t size_attack_z_width_back;
  int32_t data_airJuggle;
  int32_t size_attack_dist;
  int32_t size_proj_attack_dist;
  int32_t data_defence;
  float data_fall_defence_mul;
  int32_t data_lieDown_time;
  float size_XScale;
  float size_YScale;
  int32_t size_ground_back;
  int32_t size_ground_front;
  int32_t size_air_back;
  int32_t size_air_front;
  int32_t size_z_width;
  int32_t size_height;
  uint32_t size_proj_doScale;
  int32_t size_head_pos_x;
  int32_t size_head_pos_y;
  int32_t size_mid_pos_x;
  int32_t size_mid_pos_y;
  int32_t size_shadowOffset;
  float velocity_walk_fwd_x;
  float velocity_walk_back_x;
  float velocity_walk_up_x;
  float velocity_walk_down_x;
  float velocity_run_fwd_x;
  float velocity_run_fwd_y;
  float velocity_run_back_x;
  float velocity_run_back_y;
  float velocity_run_down_x;
  float velocity_run_down_y;
  float velocity_run_up_x;
  float velocity_run_up_y;
  float velocity_jump_y;
  float velocity_jump_new_x;
  float velocity_jump_fwd_x;
  float velocity_jump_back_x;
  float velocity_jump_up_x;
  float velocity_jump_down_x;
  float velocity_runJump_y;
  float velocity_runJump_fwd_x;
  float velocity_runJump_back_x;
  float velocity_runJump_up_x;
  float velocity_runJump_down_x;
  int32_t movement_airJump_num;
  int32_t movement_airJump_height;
  float velocity_airJump_y;
  float velocity_airJump_new_x;
  float velocity_airJump_fwd_x;
  float velocity_airJump_back_x;
  float velocity_airJump_up_x;
  float velocity_airJump_down_x;
  float movement_YAccel;
  float movement_stand_friction;
  float movement_crouch_friction;
  int32_t data_sparkNo;
  int32_t data_guard_sparkNo;
  uint32_t data_KO_echo;
  int32_t size_draw_offset_x;
  int32_t size_draw_offset_y;
  int32_t data_intPersistIndex;
  int32_t data_floatPersistIndex;
};
struct MUGEN_PLAYER_ASSERTSPECIAL_FLAGS_ {
  uint8_t noStandGuard;
  uint8_t noCrouchGuard;
  uint8_t noAirGuard;
  uint8_t noAutoTurn;
  uint8_t noShadow;
  uint8_t noJuggleCheck;
  uint8_t noWalk;
  uint8_t noUnguardable;
  uint8_t invisible;
  uint8_t _padding[3];
};
struct MUGEN_KEY_INPUTS_ {
  DIRECT_INPUT_KEYCODE inputKeyCode[30];
  undefined4 _unknonw_1;
  uint32_t jump;
  uint32_t right;
  uint32_t down;
  uint32_t left;
  uint32_t a;
  uint32_t b;
  uint32_t c;
  uint32_t x;
  uint32_t y;
  uint32_t z;
  uint32_t start;
  undefined4 _unknown_2;
  int32_t min_index;
  int32_t max_index;
  uint32_t _unknown_3;
  uint32_t flip;
};
struct MUGEN_COMMAND_TIMES_ {
  uint8_t times[128];
};
struct MUGEN_GET_HIT_VARS_ {
  int32_t XVelAdd;
  int32_t YVelAdd;
  MUGEN_PLAYER* attackedBy;
  uint32_t type;
  uint32_t animType;
  uint32_t airType;
  uint32_t groundType;
  int32_t damage;
  int32_t hitCount;
  int32_t fallCount;
  int32_t hitShakeTime;
  int32_t hitTime;
  int32_t slideTime;
  int32_t ctrlTime;
  int32_t recoverTime;
  uint32_t attr;
  float XOff;
  float YOff;
  float ZOff;
  float XVel;
  float YVel;
  float YAccel;
  uint32_t chainId;
  uint32_t guarded;
  MUGEN_PLAYER* boundedBy;
  uint32_t fall;
  int32_t fall_damage;
  float fall_XVel;
  float fall_YVel;
  uint32_t fall_recover;
  int32_t fall_time;
  int32_t fall_recoverTime;
  uint32_t fall_kill;
  MUGEN_ENV_SHAKE fall_envShake;
};
struct MUGEN_HIT_OVERRIDE_ {
  uint32_t enable;
  uint32_t attr;
  int32_t state;
  int32_t time;
  uint32_t forceAir;
};
struct MUGEN_PLAYER_AI_PLAYERS_STATE_ {
  MUGEN_PLAYER* player;
  undefined4 _unknown;
  int32_t stateNo;
  MUGEN_STATE_DEF_INFO* stateList;
};
struct MUGEN_PLAYER_AI_PARAMS_ {
  undefined4 _unknown_1;
  undefined4 _unknown_2;
  uint32_t stateType;
  int32_t screenPosX;
  int32_t posY;
  int32_t facing;
  undefined4 _unknown_3;
  undefined4 _unknown_4;
  undefined4 _unknown_5;
  int32_t lastStateNo;
  uint32_t lastStateType;
  uint32_t lastMoveType;
  uint32_t lastCtrl;
  undefined4 _unknown_6[125];
  int32_t stateNo;
  uint32_t stateType_;
  undefined4 commnands[10];
  undefined4 _unknown_7[48];
  float _unknown_8;
  undefined4 _unknown_9[15];
  float _unknown_10;
  undefined4 _unknown_11[95];
};
struct MUGEN_PLAYER_AI_ {
  uint32_t enable;
  uint32_t aiLevel;
  undefined4 _unknown_1[18];
  MUGEN_STATE_DEF_DATA* currentStateDefData;
  undefined4 _unknown_2[362];
  MUGEN_PLAYER_AI_PLAYERS_STATE _unknown_3[10];
  int32_t _unknown_4;
  undefined4 _unknown_5[57];
  MUGEN_STATE_DEF_INFO* _unknown_6;
  MUGEN_STATE_DEF_INFO* _unknown_7;
  undefined4 _unknown_8[64];
  MUGEN_PLAYER_AI_PARAMS params;
  int32_t commands[10];
  int32_t gametime;
  int32_t commandHistory[10];
  int32_t lastFiredProjId;
  int32_t preStateNo;
  MUGEN_PLAYER_STATETYPE preStateType;
  MUGEN_PLAYER_MOVETYPE preMoveType;
  uint32_t preCtrl;
  undefined4 _unknown_9[11];
};
struct MUGEN_PLAYER_BIND_ {
  int32_t time;
  float* targetScreenPosX;
  float* targetPosY;
  float* targetPosZ;
  int32_t* targetFacing;
  int32_t facing;
  float posX;
  float posY;
  float posZ;
  MUGEN_PLAYER* player;
};
struct MUGEN_PLAYER_INFO_ {
  char name[48];
  char displayName[48];
  char authorName[48];
  MUGEN_VERSION_DATA versionDate;
  MUGEN_VERSION_DATA mugenVersion;
  undefined _unknown_1[512];
  int32_t charsIdx;
  MUGEN_PLAYER_CONSTRAINTS consts;
  void* command;
  undefined4 _unknown_2;
  int32_t commandCnt;
  int32_t uniqueCommandCnt;
  MUGEN_STATE_DEF_INFO** stateList;
  MUGEN_SFF_INFO_EX* sff;
  MUGEN_ANIM_INFO_EX* anim;
  int32_t volume;
  MUGEN_SND_INFO** snd;
  char ai_filepath[512];
  void* _unknown_3;
  void* _unknown_4;
  undefined4 _unknown_5[64];
};

struct MUGEN_PLAYER_ {
  MUGEN_PLAYER_INFO* info;
  int32_t playerId;
  int32_t slotId;
  uint32_t teamSide;
  uint32_t turnCharsetIdx;
  uint32_t turnsNo;
  uint32_t isPartner;
  uint32_t isHelper;
  char debugName[48];
  MUGEN_PLAYER_CONSTRAINTS consts;
  uint32_t playerExist;
  uint32_t isFrozen;
  int32_t life;
  int32_t lifeMax;
  int32_t lifebarFront;
  int32_t lifebarBack;
  int32_t* pPower;
  int32_t* pPowerMax;
  int32_t power;
  int32_t powerMax;
  int32_t powerbar;
  int32_t powerbarCnt;
  float attackMul;
  float defenceMul;
  int32_t facing;
  int32_t turnFlag;
  uint32_t isVisible;
  float screenPosX;
  float posY;
  float posZ;
  float viewScreenPosX;
  float viewPosY;
  float viewPosZ;
  float velX;
  float velY;
  float velZ;
  int32_t offsetX;
  int32_t offsetY;
  int32_t offsetZ;
  int32_t sprPriority;
  int32_t leftAirJumpNum;
  int32_t leftBounds;
  int32_t rightBounds;
  int32_t pauseMoveTime;
  int32_t superMoveTime;
  uint32_t screenBound;
  uint32_t moveCameraX;
  uint32_t moveCameraY;
  uint32_t playerPush;
  int32_t widthEdgeFront;
  int32_t widthEdgeBack;
  int32_t widthPlayerFront;
  int32_t widthPlayerBack;
  MUGEN_PLAYER_ASSERTSPECIAL_FLAGS assertSpecialFlags;
  int32_t projContactId;
  MUGEN_PLAYER_PROJCONTACT_TYPE projContactType;
  int32_t projContactTime;
  MUGEN_PROJECTILE_INFO_EX* projectiles;
  MUGEN_TARGET_INFO* targets;
  float _unknown_1;
  float _unknown_2;
  float _unknown_3;
  float _unknown_4;
  float _unknown_5;
  undefined4 _unknown_6;
  uint32_t keyCtrl;
  undefined4 _unknown_7;
  undefined4 _unknown_8;
  MUGEN_KEY_INPUTS keyInputs;
  undefined4 _unknown_9[407];
  MUGEN_CONFIG_KEYS* configKeys;
  void* command;
  MUGEN_COMMAND_TIMES commandTimes;
  undefined _unknown_10[512];
  MUGEN_STATE_DEF_INFO** usingStateList;
  MUGEN_STATE_DEF_INFO** enforcedStateList;
  uint32_t enforcedStateListBy;
  int32_t stateNo;
  int32_t prevStateNo;
  char persistents[512];
  int32_t time;
  MUGEN_PLAYER_STATETYPE stateType;
  MUGEN_PLAYER_MOVETYPE moveType;
  MUGEN_PLAYER_PHYSICS physics;
  uint32_t ctrl;
  uint32_t isGuarding;
  int32_t idleTime;
  int32_t hitPauseTime;
  int32_t nextHitPauseTime;
  int32_t posFreeze;
  int32_t alive;
  int32_t timeSinceDeath;
  int32_t gameTime;
  MUGEN_PLAYER_MOVECONTACT_TYPE moveContactType;
  int32_t moveContactTime;
  undefined4 _unknown_13;
  uint32_t hasValidStateNo;
  int32_t var[60];
  float fvar[40];
  int32_t sysvar[5];
  float sysfvar[5];
  int32_t unhittable;
  uint32_t hitBy;
  uint32_t hitBy2;
  int32_t hitByTime;
  int32_t hitBy2Time;
  MUGEN_GET_HIT_VARS getHitVars;
  MUGEN_HIT_OVERRIDE hitOverrides[8];
  int32_t* _unknown_15;
  float _unknown_16;
  int32_t uninjuredCnt;
  int32_t* _unknown_18;
  MUGEN_HIT_DEF_PARAMS hitDefParams;
  int32_t juggle;
  float scale;
  float scaleX;
  float scaleY;
  float realScreenPosX;
  float realScreenPosY;
  int32_t _unknown_19;
  int32_t _unknown_20;
  int32_t _unknown_21;
  int32_t _unknown_22; /* related to pos x? */
  int32_t _unknown_23; /* related to pos y? */
  int32_t _unknown_24; /* related to pos z? */
  int32_t offsetGapX;
  int32_t offsetGapY;
  float angle;
  uint32_t angleDrawFlag;
  undefined4 _unknown_25;
  MUGEN_TRANS_TYPE trans;
  int32_t alphaAS;
  int32_t alphaD;
  MUGEN_AFTERIMAGE_DATA* afterImage;
  int32_t internalHitCount;
  int32_t hitCount;
  int32_t uniqHitCount;
  undefined4 _unknown_26;
  undefined4 _unknown_27;
  MUGEN_SFF_INFO_EX* sff;
  MUGEN_SFF_INFO_EX* personalPalleteSff;
  MUGEN_SFF_INFO_EX* commonPalleteSff;
  MUGEN_SFF_INFO_EX* personalPalleteSff_;
  MUGEN_ANIM_USED* anim;
  MUGEN_ANIM_INFO_EX* enforcedAnim;
  int32_t palNo;
  undefined4 _unknown_28[1152]; /* Maybe unused */
  MUGEN_PAL_GROUP palGroup;
  MUGEN_PAL_FX palFX;
  int32_t helperId;
  int32_t parentId;
  MUGEN_PLAYER* parent;
  MUGEN_PLAYER* root;
  uint32_t playerType;
  MUGEN_PLAYER_AI ai;
  MUGEN_PLAYER* p2Enemy;
  MUGEN_PLAYER* enemynear;
  uint32_t roundsExisted;
  MUGEN_PLAYER_BIND bindTo;
  uint32_t animInvalidFlag;
  MUGEN_CLIPBOARD* clipboard;
  uint32_t standBy;
};

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

static volatile uint32_t* const isMugenLogOpened_ = (volatile uint32_t* const)0x4a3948;
static volatile HWND* const MUGEN_WINDOW_ = (volatile HWND* const)0x4a7d34;
static volatile HMODULE* const hMP3PluginModule_ = (volatile HMODULE* const)0x4a7d38;
static volatile int32_t* const winamp_using_plugin_no_ = (volatile int32_t* const)0x4b0658;
static volatile FILE** const fpMugenLog_ = (volatile FILE * * const)0x4b54d4;
static volatile int32_t* const MUGEN_SND_BUFFERED_READ_ = (volatile int32_t* const)0x4b5fc0;
static volatile HMODULE* const hPluginModule_ = (volatile HMODULE* const)0x4b6040;
static volatile void** const winamp_plugins_ = (volatile void** const)0x4b6154;
static volatile int32_t* const winamp_plugin_cnt_ = (volatile int32_t* const)0x4b6158;
static volatile int32_t* const amp_loaded_ = (volatile int32_t* const)0x4b6160;

static volatile int32_t* const MyStackIndex_ = (volatile int32_t* const)0x4a19ac;
static volatile float* const clsnxscale_ = (volatile float* const)0x4a34d0;
static volatile float* const clsnyscale_ = (volatile float* const)0x4a34d4;
static volatile uint32_t* const G_CurMode_ = (volatile uint32_t* const)0x4a4588;
static volatile void** const uinpbufptr_ = (volatile void** const)0x4a5de8;
static volatile uint32_t* const KBRepeat_ = (volatile uint32_t* const)0x4a616c;
static volatile undefined4* const KBFilterRelease_ = (volatile undefined4* const)0x4a6170;
static volatile uint8_t (*const KBRawTable_)[260] = (volatile uint8_t(*const)[260])0x4a6174;
static volatile void* (*const KBRawNames_)[257] = (volatile void* (*const)[257])0x4a6278;
static volatile uint8_t (*const KBRawTableShift_)[260] = (volatile uint8_t(*const)[260])0x4a667c;
static volatile int32_t* const MUGENDATE_Y_ = (volatile int32_t* const)0x4a6a40;
static volatile int32_t* const MUGENDATE_M_ = (volatile int32_t* const)0x4a6a44;
static volatile int32_t* const MUGENDATE_D_ = (volatile int32_t* const)0x4a6a48;
static volatile int32_t* const MUGENEXPDATE_Y_ = (volatile int32_t* const)0x4a6a4c;
static volatile int32_t* const MUGENEXPDATE_M_ = (volatile int32_t* const)0x4a6a50;
static volatile int32_t* const MUGENEXPDATE_D_ = (volatile int32_t* const)0x4a6a54;
static volatile undefined4* const ShowInfoNow_0_ = (volatile undefined4* const)0x4a73a4;
static volatile int32_t* const HIres_ = (volatile int32_t* const)0x4a75ac;
static volatile uint32_t (*const CnstType_)[67] = (volatile uint32_t(*const)[67])0x4a8258;
static volatile undefined4* const nokoflag_0_ = (volatile undefined4* const)0x4a9ed8;
static volatile int32_t* const SndPanMul_ = (volatile int32_t* const)0x4aac8c;
static volatile uint32_t* const enable_lasttrk_loop_ = (volatile uint32_t* const)0x4b06c0;
static volatile char (*const jgmod_error_)[80] = (volatile char (*const)[80])0x4b06c4;
static volatile uint32_t (*const lintab_)[768] = (volatile uint32_t(*const)[768])0x4b0890;
static volatile uint16_t (*const logtab_)[104] = (volatile uint16_t(*const)[104])0x4b1490;
static volatile int32_t (*const noteperiod_)[12] = (volatile int32_t(*const)[12])0x4b1560;
static volatile int32_t (*const vib_table_)[32] = (volatile int32_t(*const)[32])0x4b1590;
static volatile int32_t (*const voice_table_)[64] = (volatile int32_t(*const)[64])0x4b1610;
static volatile int32_t* const mod_volume_ = (volatile int32_t* const)0x4b1710;
static volatile MODTYPE (*const modtypes_)[72] = (volatile MODTYPE(*const)[72])0x4b1714;
static volatile int32_t (*const mod_finetune_)[16] = (volatile int32_t(*const)[16])0x4b18c4;
static volatile int32_t* const fast_loading_ = (volatile int32_t* const)0x4b1afc;
static volatile undefined4* const ElecOutOfMem_ = (volatile undefined4* const)0x4b54e8;
static volatile int32_t* const ErrorNumber_ = (volatile int32_t* const)0x4b54ec;
static volatile void** const TempStore_ = (volatile void** const)0x4b54f4;
static volatile undefined4* const G_RenderMode_ = (volatile undefined4* const)0x4b54f8;
static volatile int32_t* const G_ColDepth_ = (volatile int32_t* const)0x4b54fc;
static volatile int32_t* const G_BytesPerPixel_ = (volatile int32_t* const)0x4b5500;
static volatile undefined4* const G_BlitMode_ = (volatile undefined4* const)0x4b5504;
static volatile undefined4* const G_BlitModeAuto_ = (volatile undefined4* const)0x4b5508;
static volatile undefined4* const G_Capabilities_ = (volatile undefined4* const)0x4b550c;
static volatile undefined4* const G_Screenptr_ = (volatile undefined4* const)0x4b5514;
static volatile AL_BITMAP* (*const G_ScreenPage_)[2] = (volatile AL_BITMAP * (*const)[2])0x4b5518;
static volatile undefined4* const scrRGB16toBGR32_ = (volatile undefined4* const)0x4b5520;
static volatile uint8_t* const framestep_0_ = (volatile uint8_t* const)0x4b5524;
static volatile int32_t* const uinpkeymap_ = (volatile int32_t* const)0x4b5530;
static volatile KB_BUFFER* const kb_buffer_ = (volatile KB_BUFFER* const)0x4b5548;
static volatile uint8_t (*const shiftflags_)[16] = (volatile uint8_t(*const)[16])0x4b5950;
static volatile int32_t* const KBHitHook_ = (volatile int32_t* const)0x4b5960;
static volatile uint32_t* const KBInstalled_ = (volatile uint32_t* const)0x4b5964;
static volatile undefined4* const KBBufferType_ = (volatile undefined4* const)0x4b596c;
static volatile undefined4* const kb_mutex_ = (volatile undefined4* const)0x4b5970;
static volatile undefined4 (*const KBAllegRemapMap_)[116] = (volatile undefined4(*const)[116])0x4b5978;
static volatile MUGEN_GAME_VAR** const g_ = (volatile MUGEN_GAME_VAR * * const)0x4b5b4c;
static volatile int32_t* const PadHitHook_ = (volatile int32_t* const)0x4b5fac;
static volatile void** const MasterPal_ = (volatile void** const)0x4b5fb0;
static volatile int32_t* const VoiceVol_ = (volatile int32_t* const)0x4b5fb8;
static volatile int32_t* const MidiVol_ = (volatile int32_t* const)0x4b5fbc;
static volatile undefined4* const SndMode_ = (volatile undefined4* const)0x4b5fc4;
static volatile uint32_t* const SndDriverInstalled_ = (volatile uint32_t* const)0x4b5fc8;
static volatile int32_t* const SndNumVoices_ = (volatile int32_t* const)0x4b5fcc;
static volatile VOICEINFO** const VoiceInfo_ = (volatile VOICEINFO * * const)0x4b5fd0;
static volatile SAMPLE** const tmpspl_ = (volatile SAMPLE * * const)0x4b5fd4;
static volatile uint32_t* const MP3Installed_ = (volatile uint32_t* const)0x4b5fd8;
static volatile uint32_t* const MP3Paused_ = (volatile uint32_t* const)0x4b5fdc;
static volatile uint32_t* const MODInstalled_ = (volatile uint32_t* const)0x4b5fe0;
static volatile uint32_t* const CDAInstalled_ = (volatile uint32_t* const)0x4b5fe4;
static volatile undefined4* const CDALoop_ = (volatile undefined4* const)0x4b5fe8;
static volatile undefined4* const CDATrack_ = (volatile undefined4* const)0x4b5fec;
static volatile undefined4* const CDAPauseflag_ = (volatile undefined4* const)0x4b5ff0;
static volatile undefined4* const ReadMode_ = (volatile undefined4* const)0x4b5ff4;
static volatile int32_t* const BufferedReadMode_ = (volatile int32_t* const)0x4b5ff8;
static volatile float* const CalculatedFPS_ = (volatile float* const)0x4b6028;
static volatile undefined4* const oldtime_0_ = (volatile undefined4* const)0x4b602c;
static volatile undefined4* const CurCall_1_ = (volatile undefined4* const)0x4b6030;
static volatile undefined4* const TPCaseSensitive_ = (volatile undefined4* const)0x4b6034;
static volatile undefined4* const V_Current_ = (volatile undefined4* const)0x4b6038;
static volatile undefined4* const V_CurrentIdx_ = (volatile undefined4* const)0x4b603c;
static volatile In_Module** const pluginInfo_ = (volatile In_Module * * const)0x4b6150;
static volatile SAMPLE** const fake_sample_ = (volatile SAMPLE * * const)0x4b64a4;
static volatile undefined4* const mod_init_ = (volatile undefined4* const)0x4b64a8;
static volatile undefined4* const enable_m15_ = (volatile undefined4* const)0x4b64ac;
static volatile undefined4* const registered_0_ = (volatile undefined4* const)0x4b64b0;
static volatile JGMOD** const of_ = (volatile JGMOD * * const)0x4b64b4;
static volatile uint8_t (*const remap_)[32] = (volatile uint8_t(*const)[32])0x4b64b8;
static volatile undefined* const chn_set_ = (volatile undefined* const)0x4b64d8;
static volatile int32_t* const mp3_volume_ = (volatile int32_t* const)0x4b68b0;
static volatile int32_t* const SyncLast_ = (volatile int32_t* const)0x4b68b4;
static volatile int32_t* const SyncCur_ = (volatile int32_t* const)0x4b68b8;
static volatile int32_t* const Ticks_ = (volatile int32_t* const)0x4b68bc;
static volatile int32_t* const SyncRate_ = (volatile int32_t* const)0x4b68c0;
static volatile int32_t* const TimerFPS_ = (volatile int32_t* const)0x4b68c4;
static volatile int32_t* const FPSUpdateTicks_ = (volatile int32_t* const)0x4b68c8;
static volatile uint32_t* const TicksUpdate_ = (volatile uint32_t* const)0x4b68cc;
static volatile uint32_t* const IncSync_ = (volatile uint32_t* const)0x4b68d0;
static volatile int32_t* const TicksPerSecond_ = (volatile int32_t* const)0x4b68d4;
static volatile uint8_t (*const padflag_)[129] = (volatile uint8_t(*const)[129])0x4b68e0;
static volatile uint8_t (*const keyflag_)[257] = (volatile uint8_t(*const)[257])0x4b6980;
static volatile uint8_t* const keypauseflag_ = (volatile uint8_t* const)0x4b6a81;
static volatile uint8_t (*const uinpflag_)[388] = (volatile uint8_t(*const)[388])0x4b6aa0;
static volatile int32_t* const S_Height_ = (volatile int32_t* const)0x4b6c24;
static volatile int32_t* const W_Height_ = (volatile int32_t* const)0x4b6c28;
static volatile int32_t* const W_Width_ = (volatile int32_t* const)0x4b6c2c;
static volatile int32_t* const V_BytesPerPixel_ = (volatile int32_t* const)0x4b6c30;
static volatile int32_t* const S_Size_ = (volatile int32_t* const)0x4b6c34;
static volatile int32_t* const W_x1_ = (volatile int32_t* const)0x4b6c38;
static volatile int32_t* const W_x2_ = (volatile int32_t* const)0x4b6c3c;
static volatile int32_t* const V_Size_ = (volatile int32_t* const)0x4b6c40;
static volatile int32_t* const W_y1_ = (volatile int32_t* const)0x4b6c44;
static volatile int32_t* const W_y2_ = (volatile int32_t* const)0x4b6c48;
static volatile int32_t* const V_Width_ = (volatile int32_t* const)0x4b6c4c;
static volatile int32_t* const V_ColDepth_ = (volatile int32_t* const)0x4b6c50;
static volatile int32_t* const W_Skip_ = (volatile int32_t* const)0x4b6c54;
static volatile int32_t* const V_Height_ = (volatile int32_t* const)0x4b6c58;
static volatile int32_t* const S_Width_ = (volatile int32_t* const)0x4b6c5c;
static volatile char (*const ErrorMessage_)[256] = (volatile char (*const)[256])0x4b6c60;
static volatile char (*const DebugTmpStr_)[256] = (volatile char (*const)[256])0x4b6d60;
static volatile MUGEN_EVAL_NODE (*const MyStack_)[128] = (volatile MUGEN_EVAL_NODE(*const)[128])0x4b6e60;
static volatile CHANNEL_INFO (*const ci_)[64] = (volatile CHANNEL_INFO(*const)[64])0x4b7060;
static volatile MUSIC_INFO* const mi_ = (volatile MUSIC_INFO* const)0x4c0060;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

/* WinMUGEN global data */

/* named by Halkaze */
#define isMugenLogOpened (*isMugenLogOpened_)
#define MUGEN_WINDOW (*MUGEN_WINDOW_)
#define hMP3PluginModule (*hMP3PluginModule_)
#define winamp_using_plugin_no (*winamp_using_plugin_no_)
#define fpMugenLog (*fpMugenLog_)
#define MUGEN_SND_BUFFERED_READ (*MUGEN_SND_BUFFERED_READ_)
#define hPluginModule (*hPluginModule_)
#define winamp_plugins (*winamp_plugins_)
#define winamp_plugin_cnt (*winamp_plugin_cnt_)
#define amp_loaded (*amp_loaded_)

/* named by Linux MUGEN */
#define MyStackIndex (*MyStackIndex_)
#define clsnxscale (*clsnxscale_)
#define clsnyscale (*clsnyscale_)
#define G_CurMode (*G_CurMode_)
#define uinpbufptr (*uinpbufptr_)
#define KBRepeat (*KBRepeat_)
#define KBFilterRelease (*KBFilterRelease_)
#define KBRawTable (*KBRawTable_)
#define KBRawNames (*KBRawNames_)
#define KBRawTableShift (*KBRawTableShift_)
#define MUGENDATE_Y (*MUGENDATE_Y_)
#define MUGENDATE_M (*MUGENDATE_M_)
#define MUGENDATE_D (*MUGENDATE_D_)
#define MUGENEXPDATE_Y (*MUGENEXPDATE_Y_)
#define MUGENEXPDATE_M (*MUGENEXPDATE_M_)
#define MUGENEXPDATE_D (*MUGENEXPDATE_D_)
#define ShowInfoNow_0 (*ShowInfoNow_0_)
#define HIres (*HIres_)
#define CnstType (*CnstType_)
#define nokoflag_0 (*nokoflag_0_)
#define SndPanMul (*SndPanMul_)
#define enable_lasttrk_loop (*enable_lasttrk_loop_)
#define jgmod_error (*jgmod_error_)
#define lintab (*lintab_)
#define logtab (*logtab_)
#define noteperiod (*noteperiod_)
#define vib_table (*vib_table_)
#define voice_table (*voice_table_)
#define mod_volume (*mod_volume_)
#define modtypes (*modtypes_)
#define mod_finetune (*mod_finetune_)
#define fast_loading (*fast_loading_)
#define ElecOutOfMem (*ElecOutOfMem_)
#define ErrorNumber (*ErrorNumber_)
#define TempStore (*TempStore_)
#define G_RenderMode (*G_RenderMode_)
#define G_ColDepth (*G_ColDepth_)
#define G_BytesPerPixel (*G_BytesPerPixel_)
#define G_BlitMode (*G_BlitMode_)
#define G_BlitModeAuto (*G_BlitModeAuto_)
#define G_Capabilities (*G_Capabilities_)
#define G_Screenptr (*G_Screenptr_)
#define G_ScreenPage (*G_ScreenPage_)
#define scrRGB16toBGR32 (*scrRGB16toBGR32_)
#define framestep_0 (*framestep_0_)
#define uinpkeymap (*uinpkeymap_)
#define kb_buffer (*kb_buffer_)
#define shiftflags (*shiftflags_)
#define KBHitHook (*KBHitHook_)
#define KBInstalled (*KBInstalled_)
#define KBBufferType (*KBBufferType_)
#define kb_mutex (*kb_mutex_)
#define KBAllegRemapMap (*KBAllegRemapMap_)
#define g (*g_)
#define PadHitHook (*PadHitHook_)
#define MasterPal (*MasterPal_)
#define VoiceVol (*VoiceVol_)
#define MidiVol (*MidiVol_)
#define SndMode (*SndMode_)
#define SndDriverInstalled (*SndDriverInstalled_)
#define SndNumVoices (*SndNumVoices_)
#define VoiceInfo (*VoiceInfo_)
#define tmpspl (*tmpspl_)
#define MP3Installed (*MP3Installed_)
#define MP3Paused (*MP3Paused_)
#define MODInstalled (*MODInstalled_)
#define CDAInstalled (*CDAInstalled_)
#define CDALoop (*CDALoop_)
#define CDATrack (*CDATrack_)
#define CDAPauseflag (*CDAPauseflag_)
#define ReadMode (*ReadMode_)
#define BufferedReadMode (*BufferedReadMode_)
#define CalculatedFPS (*CalculatedFPS_)
#define oldtime_0 (*oldtime_0_)
#define CurCall_1 (*CurCall_1_)
#define TPCaseSensitive (*TPCaseSensitive_)
#define V_Current (*V_Current_)
#define V_CurrentIdx (*V_CurrentIdx_)
#define pluginInfo (*pluginInfo_)
#define fake_sample (*fake_sample_)
#define mod_init (*mod_init_)
#define enable_m15 (*enable_m15_)
#define registered_0 (*registered_0_)
#define of (*of_)
#define remap (*remap_)
#define chn_set (*chn_set_)
#define mp3_volume (*mp3_volume_)
#define SyncLast (*SyncLast_)
#define SyncCur (*SyncCur_)
#define Ticks (*Ticks_)
#define SyncRate (*SyncRate_)
#define TimerFPS (*TimerFPS_)
#define FPSUpdateTicks (*FPSUpdateTicks_)
#define TicksUpdate (*TicksUpdate_)
#define IncSync (*IncSync_)
#define TicksPerSecond (*TicksPerSecond_)
#define padflag (*padflag_)
#define keyflag (*keyflag_)
#define keypauseflag (*keypauseflag_)
#define uinpflag (*uinpflag_)
#define S_Height (*S_Height_)
#define W_Height (*W_Height_)
#define W_Width (*W_Width_)
#define V_BytesPerPixel (*V_BytesPerPixel_)
#define S_Size (*S_Size_)
#define W_x1 (*W_x1_)
#define W_x2 (*W_x2_)
#define V_Size (*V_Size_)
#define W_y1 (*W_y1_)
#define W_y2 (*W_y2_)
#define V_Width (*V_Width_)
#define V_ColDepth (*V_ColDepth_)
#define W_Skip (*W_Skip_)
#define V_Height (*V_Height_)
#define S_Width (*S_Width_)
#define ErrorMessage (*ErrorMessage_)
#define DebugTmpStr (*DebugTmpStr_)
#define MyStack (*MyStack_)
#define ci (*ci_)
#define mi (*mi_)

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

/* WinMUGEN functions */

static void (*const AftImgSetup)(MUGEN_AFTERIMAGE_DATA* afterImage, value32_t* initData, MUGEN_ANIM_USED* anim) = (void (*const)(MUGEN_AFTERIMAGE_DATA*, value32_t*, MUGEN_ANIM_USED*))0x401220;
static uint32_t (*const AftImgUpdate)(MUGEN_AFTERIMAGE_DATA* aftImgData, float posX, float posY, float scaleX, float scaleY, float angle, uint32_t hflip, int32_t moving) = (uint32_t(*const)(MUGEN_AFTERIMAGE_DATA*, float, float, float, float, float, uint32_t, int32_t))0x401250;
static MUGEN_ANIM_USED* (*const AnimUpdate)(MUGEN_ANIM_USED* anim) = (MUGEN_ANIM_USED * (*const)(MUGEN_ANIM_USED*))0x402850;
static void (*const AnimResetAction)(MUGEN_ANIM_USED* anim) = (void (*const)(MUGEN_ANIM_USED*))0x402c80;
static void (*const AnimChangeAction)(MUGEN_ANIM_USED* anim, int32_t key1, int32_t animNo) = (void (*const)(MUGEN_ANIM_USED*, int32_t, int32_t))0x402d60;
static int32_t (*const AnimCurIDno)(MUGEN_ANIM_USED* anim) = (int32_t(*const)(MUGEN_ANIM_USED*))0x403d50;
static int32_t (*const AnimCurElemStartTime)(MUGEN_ANIM_USED* anim, int32_t elemNo) = (int32_t(*const)(MUGEN_ANIM_USED*, int32_t))0x403d70;
static int32_t (*const AnimElemNo)(MUGEN_ANIM_USED* anim, int32_t frame) = (int32_t(*const)(MUGEN_ANIM_USED * anim, int32_t frame))0x403f70;
static int32_t (*const AnimGetLooptime)(MUGEN_ANIM_USED* anim) = (int32_t(*const)(MUGEN_ANIM_USED*))0x4041e0;
static int32_t (*const AnimPerArrayAdd)(MUGEN_ANIM_INFO_EX* animPerArray, MUGEN_ANIM_INFO_EX* anim, MUGEN_SFF_INFO_EX* sff, int32_t /*_unknown*/, int32_t animNo, int32_t posX, int32_t posY, int32_t hFlip, int32_t /*_unknown*/) = (int32_t(*const)(MUGEN_ANIM_INFO_EX*, MUGEN_ANIM_INFO_EX*, MUGEN_SFF_INFO_EX*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t))0x404df0;
static void (*const AnimPerArraySetNo)(MUGEN_ANIM_INFO_EX* animPerArray, int32_t id, int32_t under) = (void (*const)(MUGEN_ANIM_INFO_EX*, int32_t, int32_t))0x404f80;
static void (*const AnimPerArrayUpdate)(MUGEN_ANIM_INFO_EX* animInfoEx) = (void (*const)(MUGEN_ANIM_INFO_EX*))0x404fd0;
static void (*const ShowExp)(const char* errmsg, const MUGEN_EVAL_VALUE* eval, MUGEN_PLAYER* player) = (void (*const)(const char*, const MUGEN_EVAL_VALUE*, MUGEN_PLAYER*))0x4073e0;
static int32_t (*const EvalExpressionI)(MUGEN_PLAYER* player, MUGEN_EVAL_VALUE* eval, uint32_t warnNo) = (int32_t(*const)(MUGEN_PLAYER*, MUGEN_EVAL_VALUE*, uint32_t))0x4075e0;
static float (*const EvalExpressionF)(MUGEN_PLAYER* player, MUGEN_EVAL_VALUE* eval) = (float (*const)(MUGEN_PLAYER*, MUGEN_EVAL_VALUE*))0x4076d0;
static void (*const ArrayDelete)(ABSTRUCT_ARRAY_INFO* info, int32_t index) = (void (*const)(ABSTRUCT_ARRAY_INFO*, int32_t))0x408d10;
static void (*const ArrayClear)(ABSTRUCT_ARRAY_INFO* info) = (void (*const)(ABSTRUCT_ARRAY_INFO*))0x408de0;
static int32_t (*const ArrayFind)(ABSTRUCT_ARRAY_INFO* pInfo, int32_t key1, int32_t key2) = (int32_t(*const)(ABSTRUCT_ARRAY_INFO*, int32_t, int32_t))0x408f50;
static void* (*const ArrayAccessGrpItem)(ABSTRUCT_ARRAY_INFO* info, int32_t key1, int32_t key2) = (void* (*const)(ABSTRUCT_ARRAY_INFO*, int32_t, int32_t))0x4090f0;
static void* (*const ArrayScanFirst)(ABSTRUCT_ARRAY_INFO* pInfo) = (void* (*const)(ABSTRUCT_ARRAY_INFO*))0x409240;
static void* (*const ArrayScanNext)(ABSTRUCT_ARRAY_INFO* pInfo) = (void* (*const)(ABSTRUCT_ARRAY_INFO*))0x4092b0;
static void (*const ClipboardClear)(MUGEN_CLIPBOARD* clipboard) = (void (*const)(MUGEN_CLIPBOARD*))0x413180;
static void (*const ClipboardPrint)(MUGEN_CLIPBOARD* clipboard, const char* message, ...) = (void (*const)(MUGEN_CLIPBOARD*, const char*, ...))0x4131a0;
static void (*const ClipboardAppend)(MUGEN_CLIPBOARD* clipboard, const char* message, ...) = (void (*const)(MUGEN_CLIPBOARD*, const char*, ...))0x4131f0;
static void (*const KBClearCommandValidTimes)(MUGEN_COMMAND_TIMES* commandTimes) = (void (*const)(MUGEN_COMMAND_TIMES*))0x414300;
static void (*const KBClearCommandLastTimes)(MUGEN_COMMAND_TIMES* commandTimes) = (void (*const)(MUGEN_COMMAND_TIMES*))0x414320;
static uint32_t (*const KBCommandIsValid)(MUGEN_COMMAND_TIMES* commandTimes, int32_t commandIndex) = (uint32_t(*const)(MUGEN_COMMAND_TIMES*, int32_t))0x414380;
static void (*const Warn)(MUGEN_PLAYER* player, const char* warnMessage) = (void (*const)(MUGEN_PLAYER*, const char*))0x4155f0;
static void (*const VWarn)(MUGEN_PLAYER* player, const char* warningMessage, ...) = (void (*const)(MUGEN_PLAYER* player, const char* warningMessage, ...))0x415630;
static void (*const WarnR)(MUGEN_PLAYER* player, MUGEN_PLAYER* redirectTo, const char* warnMessage) = (void (*const)(MUGEN_PLAYER*, MUGEN_PLAYER*, const char*))0x4156a0;
static void (*const ErrorExit)(void) = (void (*const)(void))0x415860;
static void (*const DrawToScreen)(void) = (void (*const)(void))0x4174e0;
static void (*const DebugErrorExit)(const char* errorMsg) = (void (*const)(const char*))0x4187d0;
static void (*const ExplodArrayUpdate)(MUGEN_EXPLODS_INFO* explodsInfo) = (void (*const)(MUGEN_EXPLODS_INFO*))0x419060;
static void (*const ExplodArrayReset)(MUGEN_EXPLODS_INFO* explods) = (void (*const)(MUGEN_EXPLODS_INFO*))0x4199e0;
static void (*const ExplodMakeFromInfo)(MUGEN_PLAYER* player, MUGEN_SC_PARAMS_EX_EXPLOD* paramsEx, MUGEN_PLAYER_REDIRECTS* redirects) = (void (*const)(MUGEN_PLAYER*, MUGEN_SC_PARAMS_EX_EXPLOD*, MUGEN_PLAYER_REDIRECTS*))0x419a20;
static void (*const ExplodDefault)(MUGEN_EXPLODS_DATA* explod) = (void (*const)(MUGEN_EXPLODS_DATA*))0x419c80;
static void (*const ExplodModifyFromInfo)(MUGEN_PLAYER* player, MUGEN_SC_PARAMS_EX_EXPLOD* paramsEx, MUGEN_PLAYER_REDIRECTS* redirects) = (void (*const)(MUGEN_PLAYER*, MUGEN_SC_PARAMS_EX_EXPLOD*, MUGEN_PLAYER_REDIRECTS*))0x419d40;
static void (*const ExplodSetParams)(MUGEN_PLAYER* player, MUGEN_EXPLODS_DATA* explod, MUGEN_SC_PARAMS_EX_EXPLOD* paramsEx, MUGEN_PLAYER_REDIRECTS* redirects, uint32_t isUpdate) = (void (*const)(MUGEN_PLAYER*, MUGEN_EXPLODS_DATA*, MUGEN_SC_PARAMS_EX_EXPLOD*, MUGEN_PLAYER_REDIRECTS*, uint32_t))0x419dd0;
static int32_t (*const ExplodAdd)(MUGEN_EXPLODS_INFO* explods, int32_t animNo, MUGEN_ANIM_INFO_EX* anim, MUGEN_SFF_INFO_EX* sff) = (int32_t(*const)(MUGEN_EXPLODS_INFO*, int32_t, MUGEN_ANIM_INFO_EX*, MUGEN_SFF_INFO_EX*))0x41a4a0;
static void (*const ExplodRemoveID)(MUGEN_EXPLODS_INFO* explods, int32_t playerId, int32_t explodId) = (void (*const)(MUGEN_EXPLODS_INFO*, int32_t, int32_t))0x41a670;
static void (*const ExplodRemoveGetHit)(MUGEN_EXPLODS_INFO* explodsInfo, int32_t playerId) = (void (*const)(MUGEN_EXPLODS_INFO*, int32_t))0x41a6d0;
static void (*const ExplodBindChange)(MUGEN_EXPLODS_INFO* explods, int32_t playerId, int32_t explodId, int32_t bindtime) = (void (*const)(MUGEN_EXPLODS_INFO*, int32_t, int32_t, int32_t))0x41a770;
static int32_t (*const ExplodCount)(MUGEN_EXPLODS_INFO* explods, int32_t ownerId, int32_t explodId) = (int32_t(*const)(MUGEN_EXPLODS_INFO*, int32_t, int32_t))0x41a7c0;
static int32_t (*const GameRound)(void) = (int32_t(*const)(void))0x41ed20;
static void (*const CameraMoveP)(void) = (void (*const)(void))0x421790;
static void (*const ComboAdd)(int32_t teamside, int32_t value) = (void (*const)(int32_t, int32_t))0x421ef0;
static void (*const PlayerComboCountCheck)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x4222a0;
static MUGEN_AFTERIMAGE_DATA* (*const RequestNewAftImg)(MUGEN_AFTERIMAGE_INFO* afterImage) = (MUGEN_AFTERIMAGE_DATA * (*const)(MUGEN_AFTERIMAGE_INFO*))0x423630;
static void (*const ProjArrayAftImgUpdate)(MUGEN_PROJECTILE_INFO_EX* projInfo) = (void (*const)(MUGEN_PROJECTILE_INFO_EX*))0x423830;
static int32_t (*const TeamLifeBack)(int32_t teamIndex) = (int32_t(*const)(int32_t))0x423be0;
static void (*const WinIconCheck)(int32_t winTeamside, uint32_t lastHitAttr, int32_t winIconType) = (void (*const)(int32_t, uint32_t, int32_t))0x423ea0;
static uint32_t (*const TeamHasFullLife)(int32_t teamside) = (uint32_t(*const)(int32_t))0x423f90;
static MUGEN_PLAYER* (*const HelperMake)(MUGEN_PLAYER* player, MUGEN_SC_PARAMS_EX_HELPER* paramsEx, MUGEN_PLAYER_REDIRECTS* redirects) = (MUGEN_PLAYER * (*const)(MUGEN_PLAYER*, MUGEN_SC_PARAMS_EX_HELPER*, MUGEN_PLAYER_REDIRECTS*))0x4246a0;
static void (*const HelperDestroy)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x424de0;
static MUGEN_PLAYER* (*const HelperParent)(MUGEN_PLAYER* player) = (MUGEN_PLAYER * (*const)(MUGEN_PLAYER*))0x424ef0;
static MUGEN_PLAYER* (*const HelperRoot)(MUGEN_PLAYER* player) = (MUGEN_PLAYER * (*const)(MUGEN_PLAYER*))0x424f20;
static int32_t (*const HelperCount)(MUGEN_PLAYER* player, int32_t helperId) = (int32_t(*const)(MUGEN_PLAYER*, int32_t))0x424f30;
static MUGEN_PLAYER* (*const HelperAccessID)(MUGEN_PLAYER* player, int32_t helperId) = (MUGEN_PLAYER * (*const)(MUGEN_PLAYER*, int32_t))0x424fa0;
static void (*const KBISetFlip)(MUGEN_KEY_INPUTS* keyInputs, int32_t value) = (void (*const)(MUGEN_KEY_INPUTS*, int32_t))0x429410;
static void (*const KBIUpdate)(MUGEN_CONFIG_KEYS* configKeys, MUGEN_KEY_INPUTS* keyInputs, uint32_t intCircBuf) = (void (*const)(MUGEN_CONFIG_KEYS*, MUGEN_KEY_INPUTS*, uint32_t))0x4295f0;
static int32_t (*const IntCircBufGet)(MUGEN_INT_CIRC_BUF* intCircBuf) = (int32_t(*const)(MUGEN_INT_CIRC_BUF*))0x42a730;
static uint32_t (*const GameModeInPassiveFightScreen)(void) = (uint32_t(*const)(void))0x42cda0;
static void (*const GameNextRound)(void) = (void (*const)(void))0x42da90;
static void (*const GameRoundResetPlayerPos)(void) = (void (*const)(void))0x42e7d0;
static int32_t (*const GameRoundWinner)(void) = (int32_t(*const)(void))0x42e8b0;
static int32_t (*const GameMatchWinner)(void) = (int32_t(*const)(void))0x42e8c0;
static void (*const LogMatch)(void) = (void (*const)(void))0x42eb20;
static void (*const PlayerResetAI)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x434980;
static void (*const PlayerAI)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x434a00;
static uint32_t (*const AIInsertCommand)(int32_t* commandHistory, int32_t commandId) = (uint32_t(*const)(int32_t*, int32_t))0x434eb0;
static void (*const AICopyCommands)(int32_t* commands, int32_t* counts) = (void (*const)(int32_t*, int32_t*))0x434ef0;
static int32_t* (*const AIClearCommands)(int32_t* counts) = (int32_t * (*const)(int32_t*))0x434f30;
static int32_t (*const AICountCommands)(int32_t* counts) = (int32_t(*const)(int32_t*))0x434f40;
static uint32_t (*const PlayerAILearnMoveStart)(MUGEN_PLAYER* player) = (uint32_t(*const)(MUGEN_PLAYER*))0x434f60;
static void (*const PlayerAILearnMoveUpdate)(MUGEN_PLAYER* player, uint32_t isRunnable) = (void (*const)(MUGEN_PLAYER*, uint32_t))0x4350d0;
static int32_t (*const PlayerAIMsgAttack)(MUGEN_PLAYER* player) = (int32_t(*const)(MUGEN_PLAYER*))0x435d80;
static void (*const PlayerAIClearMsg)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x4361e0;
static void (*const PlayerAIMsgStateUpdate)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x4361f0;
static void (*const PlayerAISctrlProjectile)(MUGEN_PLAYER* player, MUGEN_PROJECTILE_DATA* projectile) = (void (*const)(MUGEN_PLAYER*, MUGEN_PROJECTILE_DATA*))0x436310;
static MUGEN_PLAYER* (*const PlayerNearestEnemy)(MUGEN_PLAYER* player) = (MUGEN_PLAYER * (*const)(MUGEN_PLAYER*))0x439530;
static MUGEN_PLAYER* (*const PartnerAccess)(MUGEN_PLAYER* player, int32_t no) = (MUGEN_PLAYER * (*const)(MUGEN_PLAYER*, int32_t))0x439720;
static int32_t (*const PartnerCount)(MUGEN_PLAYER* player) = (int32_t(*const)(MUGEN_PLAYER*))0x439790;
static MUGEN_PLAYER* (*const EnemyAccess)(MUGEN_PLAYER* player, int32_t no) = (MUGEN_PLAYER * (*const)(MUGEN_PLAYER*, int32_t))0x439800;
static int32_t (*const EnemyCount)(MUGEN_PLAYER* player) = (int32_t(*const)(MUGEN_PLAYER*))0x439880;
static MUGEN_PLAYER* (*const EnemyAccessNear)(MUGEN_PLAYER* player, int32_t no) = (MUGEN_PLAYER * (*const)(MUGEN_PLAYER*, int32_t))0x4398e0;
static MUGEN_PLAYER* (*const PlayerAccessID)(int32_t playerId) = (MUGEN_PLAYER * (*const)(int32_t))0x439a00;
static int32_t (*const PlayerGetDamagedLife)(MUGEN_PLAYER* player) = (int32_t(*const)(MUGEN_PLAYER*))0x439a60;
static int32_t (*const PlayerDistX)(MUGEN_PLAYER* playerA, MUGEN_PLAYER* playerB) = (int32_t(*const)(MUGEN_PLAYER*, MUGEN_PLAYER*))0x439ad0;
static int32_t (*const PlayerBodyDistX)(MUGEN_PLAYER* playerA, MUGEN_PLAYER* playerB) = (int32_t(*const)(MUGEN_PLAYER*, MUGEN_PLAYER*))0x439b00;
static uint32_t (*const PlayerInAnyGuardDist)(MUGEN_PLAYER* player) = (uint32_t(*const)(MUGEN_PLAYER*))0x439c00;
static uint32_t (*const PlayerAnimExist)(MUGEN_PLAYER* player, int32_t animNo) = (uint32_t(*const)(MUGEN_PLAYER*, int32_t))0x439f10;
static uint32_t (*const PlayerSelfAnimExist)(MUGEN_PLAYER* player, int32_t animNo) = (uint32_t(*const)(MUGEN_PLAYER*, int32_t))0x439fe0;
static int32_t (*const PlayerLyingDead)(MUGEN_PLAYER* player) = (int32_t(*const)(MUGEN_PLAYER*))0x43a030;
static MUGEN_TARGET_DATA* (*const PlayerFindTarget)(MUGEN_TARGET_INFO* targets, MUGEN_PLAYER* targetPlayer) = (MUGEN_TARGET_DATA * (*const)(MUGEN_TARGET_INFO*, MUGEN_PLAYER*))0x43a050;
static MUGEN_TARGET_DATA* (*const TargetAccessID)(MUGEN_TARGET_INFO* targets, int32_t targetId) = (MUGEN_TARGET_DATA * (*const)(MUGEN_TARGET_INFO*, int32_t))0x43a080;
static int32_t (*const TargetCount)(MUGEN_TARGET_INFO* targets, int32_t hitId) = (int32_t(*const)(MUGEN_TARGET_INFO*, int32_t))0x43a0c0;
static void (*const PlayerKBUpdate)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x43a110;
static void (*const PlayerReset)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x440300;
static void (*const PlayerEnableSet)(int32_t slotId, uint32_t value) = (void (*const)(int32_t, uint32_t))0x440830;
static uint32_t (*const PlayerChangeState)(MUGEN_PLAYER* player, int32_t stateNo) = (uint32_t(*const)(MUGEN_PLAYER*, int32_t))0x440b60;
static void (*const PlayerLifeSet)(MUGEN_PLAYER* player, int32_t value) = (void (*const)(MUGEN_PLAYER*, int32_t))0x440bf0;
static void (*const PlayerPowerSet)(MUGEN_PLAYER* player, int32_t value) = (void (*const)(MUGEN_PLAYER*, int32_t))0x440d90;
static void (*const PlayerChangeAnim)(MUGEN_PLAYER* player, int32_t animNo) = (void (*const)(MUGEN_PLAYER*, int32_t))0x440de0;
static void (*const PlayerSelfAnim)(MUGEN_PLAYER* player, int32_t animNo) = (void (*const)(MUGEN_PLAYER*, int32_t))0x4410b0;
static void (*const PlayerSelfAnimElem)(MUGEN_PLAYER* player, int32_t animNo, int32_t animElemNo) = (void (*const)(MUGEN_PLAYER*, int32_t, int32_t))0x441180;
static void (*const PlayerAutoTurn)(MUGEN_PLAYER* player, MUGEN_PLAYER* enemy) = (void (*const)(MUGEN_PLAYER*, MUGEN_PLAYER*))0x441260;
static void (*const PlayerTurnAround)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x441320;
static void (*const PlayerUpdate)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x441350;
static void (*const PlayerUpdateBindTo)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x4424d0;
static void (*const GameClsnUpdate)(void) = (void (*const)(void))0x442800;
static void (*const PlayerTakeDamage)(MUGEN_PLAYER* player, int32_t damage, uint32_t kill, uint32_t absolute) = (void (*const)(MUGEN_PLAYER*, int32_t, uint32_t, uint32_t))0x444cf0;
static void (*const PlayerDropBoundTargets)(MUGEN_PLAYER* player, MUGEN_PLAYER* keepPlayer) = (void (*const)(MUGEN_PLAYER*, MUGEN_PLAYER*))0x4465f0;
static int32_t (*const PlayerSparkCreate)(MUGEN_PLAYER* player, int32_t animNo, int32_t posX, int32_t posY, uint32_t anim_s_flag, uint32_t inverse, uint32_t isGuarded) = (int32_t(*const)(MUGEN_PLAYER*, int32_t, int32_t, int32_t, uint32_t, uint32_t, uint32_t))0x446750;
static void (*const PlayerMakeDust)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x446870;
static void (*const PlayerCalcDraw)(MUGEN_PLAYER* player) = (void (*const)(MUGEN_PLAYER*))0x4469e0;
static void (*const MasterPalMul)(int32_t red, int32_t green, int32_t blue) = (void (*const)(int32_t, int32_t, int32_t))0x4488f0;
static void (*const PalGrpRemove)(MUGEN_PAL_GROUP palGroup) = (void (*const)(MUGEN_PAL_GROUP))0x449760;
static void (*const PalGrpAddSpr)(MUGEN_SFF_INFO_EX* sff, MUGEN_PAL_GROUP palGroup) = (void (*const)(MUGEN_SFF_INFO_EX*, MUGEN_PAL_GROUP))0x449880;
static MUGEN_PAL_GROUP* (*const PalGrpMakeFlag)(MUGEN_PAL_GROUP* palGrp, uint32_t flag, int32_t index) = (MUGEN_PAL_GROUP * (*const)(MUGEN_PAL_GROUP*, uint32_t, int32_t))0x44a0f0;
static MUGEN_PAL_GROUP* (*const PalGrpOrFlag)(MUGEN_PAL_GROUP* palGrp, MUGEN_PAL_GROUP flag1, MUGEN_PAL_GROUP flag2) = (MUGEN_PAL_GROUP * (*const)(MUGEN_PAL_GROUP*, MUGEN_PAL_GROUP, MUGEN_PAL_GROUP))0x44a1a0;
static MUGEN_PAL_GROUP* (*const PalGrpXorFlag)(MUGEN_PAL_GROUP* palGrp, MUGEN_PAL_GROUP flag1, MUGEN_PAL_GROUP flag2) = (MUGEN_PAL_GROUP * (*const)(MUGEN_PAL_GROUP*, MUGEN_PAL_GROUP, MUGEN_PAL_GROUP))0x44a1d0;
static uint32_t (*const PalGrpFlagIsNonZero)(MUGEN_PAL_GROUP palGroup) = (uint32_t(*const)(MUGEN_PAL_GROUP))0x44a240;
static void (*const PalFXReset)(MUGEN_PAL_FX* palFX) = (void (*const)(MUGEN_PAL_FX*))0x44a260;
static uint32_t (*const PrecacheRequestTeam)(void* param_1) = (uint32_t(*const)(void*))0x44a730;
static uint32_t (*const PrecacheRequestNextArcadeTeam)(void) = (uint32_t(*const)(void))0x44a9e0;
static uint32_t (*const PrecacheStart)(void) = (uint32_t(*const)(void))0x44ac00;
static void (*const PrecacheFinish)(void) = (void (*const)(void))0x44adf0;
static int32_t (*const ProjArrayAdd)(MUGEN_PLAYER* owner, MUGEN_PROJECTILE_INFO_EX* projectiles, MUGEN_PROJECTILE_DATA* projData, int32_t projAnim) = (int32_t(*const)(MUGEN_PLAYER*, MUGEN_PROJECTILE_INFO_EX*, MUGEN_PROJECTILE_DATA*, int32_t))0x44b180;
static void (*const ProjArrayDelete)(MUGEN_PROJECTILE_INFO_EX* projInfoEx, int32_t index) = (void (*const)(MUGEN_PROJECTILE_INFO_EX*, int32_t))0x44b250;
static void (*const ProjArrayUpdate)(MUGEN_PROJECTILE_INFO_EX* projInfoEx) = (void (*const)(MUGEN_PROJECTILE_INFO_EX*))0x44b2e0;
static void (*const ProjArrayCalcDraw)(MUGEN_PROJECTILE_INFO_EX* projInfoEx) = (void (*const)(MUGEN_PROJECTILE_INFO_EX*))0x44b6f0;
static int32_t (*const ProjArrayCountActive)(MUGEN_PROJECTILE_INFO_EX* projInfo) = (int32_t(*const)(MUGEN_PROJECTILE_INFO_EX*))0x44b7e0;
static int32_t (*const ProjArrayCountActiveID)(MUGEN_PROJECTILE_INFO_EX* projectiles, int32_t projId) = (int32_t(*const)(MUGEN_PROJECTILE_INFO_EX * projectiles, int32_t projId))0x44b810;
static void (*const SndVoiceStart)(int32_t index) = (void (*const)(int32_t))0x44cd60;
static void (*const SndVoiceSetVol)(int32_t index, int32_t volume) = (void (*const)(int32_t, int32_t))0x44ce70;
static void (*const SndVoiceSetFreq)(int32_t index, int32_t frequency) = (void (*const)(int32_t, int32_t))0x44ced0;
static int32_t (*const SndVoiceGetFreq)(int32_t index) = (int32_t(*const)(int32_t))0x44cf00;
static void (*const SndVoiceSetPan)(int32_t index, int32_t pan) = (void (*const)(int32_t index, int32_t pan))0x44cf30;
static void (*const SndVoiceSetLoop)(int32_t index, int32_t isLoop) = (void (*const)(int32_t, int32_t))0x44cfb0;
static int32_t (*const SndVoiceCleanup)(int32_t sndID, MUGEN_SND_INFO** snd, int32_t groupNo, int32_t sndNo) = (int32_t(*const)(int32_t, MUGEN_SND_INFO**, int32_t, int32_t))0x44d100;
static void (*const SndIDStop)(int32_t sndID) = (void (*const)(int32_t))0x44d250;
static uint32_t (*const SndIDIsPlaying)(int32_t sndID) = (uint32_t(*const)(int32_t))0x44d350;
static int32_t (*const SndIDGetChannel)(int32_t sndID) = (int32_t(*const)(int32_t sndID))0x44d3c0;
static int32_t (*const SndCorrectVolOff)(int32_t volume) = (int32_t(*const)(int32_t))0x44db00;
static void (*const GameSndPlay)(MUGEN_SND_INFO** snd, int32_t groupNo, int32_t itemNo, int32_t volume) = (void (*const)(MUGEN_SND_INFO**, int32_t, int32_t, int32_t))0x44e2d0;
static void (*const GameSndPlayIDPos)(int32_t sndID, int32_t posX, MUGEN_SND_INFO** snd, int32_t groupNo, int32_t sndNo) = (void (*const)(int32_t, int32_t, MUGEN_SND_INFO**, int32_t, int32_t))0x44e3b0;
static int32_t (*const ScrPositionToPan)(int32_t pan) = (int32_t(*const)(int32_t pan))0x44e4e0;
static int32_t (*const PanVolumeAdjust)(int32_t volume) = (int32_t(*const)(int32_t))0x44e560;
static void (*const GameSetVol)(int32_t wavVolume, int32_t midiVolume) = (void (*const)(int32_t, int32_t))0x44e570;
static int32_t (*const PlayerSndID)(MUGEN_PLAYER* player, int32_t channel) = (int32_t(*const)(MUGEN_PLAYER*, int32_t))0x44e5e0;
static MUGEN_SFF_INFO_EX* (*const SpriteArrayNewInstanceOnto)(MUGEN_SFF_INFO_EX* dest, MUGEN_SFF_INFO_EX* src) = (MUGEN_SFF_INFO_EX * (*const)(MUGEN_SFF_INFO_EX*, MUGEN_SFF_INFO_EX*))0x44ead0;
static uint32_t (*const PlayerDoSCtrlApplyElem)(MUGEN_PLAYER* player, MUGEN_SC_DATA* scData, MUGEN_PLAYER_REDIRECTS* redirects) = (uint32_t(*const)(MUGEN_PLAYER*, MUGEN_SC_DATA*, MUGEN_PLAYER_REDIRECTS*))0x46e750;
static uint32_t (*const PlayerSCtrlApplyElem)(MUGEN_PLAYER* player, MUGEN_SC_DATA* scData, MUGEN_PLAYER_REDIRECTS* redirects) = (uint32_t(*const)(MUGEN_PLAYER*, MUGEN_SC_DATA*, MUGEN_PLAYER_REDIRECTS*))0x46e800;
static uint32_t (*const SCtrlInitAftImgParams)(MUGEN_SC_PARAMS_EX_AFTERIMAGE* paramsEx, MUGEN_AFTERIMAGE_DATA* afterImage, MUGEN_ANIM_USED* anim, MUGEN_PLAYER* player) = (uint32_t(*const)(MUGEN_SC_PARAMS_EX_AFTERIMAGE*, MUGEN_AFTERIMAGE_DATA*, MUGEN_ANIM_USED*, MUGEN_PLAYER*))0x472120;
static uint32_t (*const SCtrlInitEnvShake)(MUGEN_SC_PARAMS_EX_ENVSHAKE* paramsEx, MUGEN_ENV_SHAKE* envShake, MUGEN_PLAYER* player) = (uint32_t(*const)(MUGEN_SC_PARAMS_EX_ENVSHAKE*, MUGEN_ENV_SHAKE*, MUGEN_PLAYER*))0x4725e0;
static uint32_t (*const SCtrlInitPalFX)(MUGEN_SC_PARAMS_EX_PALFX* paramsEx, MUGEN_PAL_FX* palFx, MUGEN_PLAYER* player) = (uint32_t(*const)(MUGEN_SC_PARAMS_EX_PALFX*, MUGEN_PAL_FX*, MUGEN_PLAYER*))0x473010;
static void (*const SCtrlDoPlaySndInfo)(MUGEN_PLAYER* player, MUGEN_SC_PARAMS_EX_PLAYSND* paramsEx) = (void (*const)(MUGEN_PLAYER*, MUGEN_SC_PARAMS_EX_PLAYSND*))0x4733b0;
static uint32_t (*const SCtrlInitHitOverride)(MUGEN_SC_PARAMS_EX_HITOVERRIDE* scParamsEx, MUGEN_HIT_OVERRIDE* hitOverride, MUGEN_PLAYER* player) = (uint32_t(*const)(MUGEN_SC_PARAMS_EX_HITOVERRIDE*, MUGEN_HIT_OVERRIDE*, MUGEN_PLAYER*))0x473780;
static uint32_t (*const SCtrlInitHitDef)(MUGEN_SC_PARAMS_EX_HITDEF* paramsEx, MUGEN_HIT_DEF_PARAMS* pHitDefParams, MUGEN_PLAYER* player) = (uint32_t(*const)(MUGEN_SC_PARAMS_EX_HITDEF*, MUGEN_HIT_DEF_PARAMS*, MUGEN_PLAYER*))0x474fe0;
static int32_t (*const SCtrlInitProjectile)(MUGEN_SC_PARAMS_EX_PROJECTILE* paramsEx, MUGEN_PLAYER* player, MUGEN_PLAYER* enemyFirst, MUGEN_PLAYER* owner) = (int32_t(*const)(MUGEN_SC_PARAMS_EX_PROJECTILE*, MUGEN_PLAYER*, MUGEN_PLAYER*, MUGEN_PLAYER*))0x476750;
static uint32_t (*const SCtrlInitPause)(MUGEN_SC_PARAMS_EX_PAUSE* paramsEx, uint32_t pauseType, MUGEN_PLAYER* player) = (uint32_t(*const)(MUGEN_SC_PARAMS_EX_PAUSE*, uint32_t, MUGEN_PLAYER*))0x477560;
static uint32_t (*const SCtrlTrigArrayTest)(MUGEN_PLAYER* player, MUGEN_TRIGGER_INFO* triggers, int32_t triggerCnt) = (uint32_t(*const)(MUGEN_PLAYER*, MUGEN_TRIGGER_INFO*, int32_t))0x47a810;
static void (*const SCtrlTrigEval)(MUGEN_PLAYER* player, MUGEN_EVAL_TRIGGER* trig) = (void (*const)(MUGEN_PLAYER*, MUGEN_EVAL_TRIGGER*))0x47aa60;
static uint32_t (*const SPopI)(MUGEN_PLAYER* player, int32_t* pInt) = (uint32_t(*const)(MUGEN_PLAYER*, int32_t*))0x47d5b0;
static uint32_t (*const SPopF)(MUGEN_PLAYER* /*unused*/, float* pFloat) = (uint32_t(*const)(MUGEN_PLAYER*, float*))0x47d640;
static void (*const StackUnderflow)(void) = (void (*const)(void))0x47d6c0;
static void (*const PlayerGetRedirInfo)(MUGEN_PLAYER* player, MUGEN_PLAYER_REDIRECTS* redirects) = (void (*const)(MUGEN_PLAYER*, MUGEN_PLAYER_REDIRECTS*))0x47e800;
static uint32_t (*const PlayerSCtrlUpdate)(MUGEN_PLAYER* player) = (uint32_t(*const)(MUGEN_PLAYER*))0x47f3e0;
static void (*const PlayerSCtrlUpdateSpec)(MUGEN_PLAYER* player, int32_t stateNo, uint8_t flags) = (void (*const)(MUGEN_PLAYER*, int32_t, uint8_t))0x47f7d0;
static void (*const W_Cls)(uint32_t param_1) = (void (*const)(uint32_t))0x487680;

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

/* WinMUGEN (勝手に追加) */
struct TPFILE {
    void* unknown;
};
typedef enum MUGEN_ASSERT_SPECIAL_TYPE_ {
    TYPE_AS_GLOBAL,
    TYPE_AS_PLAYER
} MUGEN_ASSERT_SPECIAL_TYPE;

struct MUGEN_SC_DATA_EX_ {
    MUGEN_TRIGGER_INFO* triggers;
    uint32_t triggerCnt;
    int32_t persistent;
    int32_t ignorehitpause;
    int scID;
    int exscID;
    void *params;
    undefined4 unused_1;
    undefined4 unused_2;
    MUGEN_EVAL_VALUE unused_params[5];
    MUGEN_SC_PARAMS_EX unused_paramsEx;
} typedef MUGEN_SC_DATA_EX;

static auto TPAccessFirstLine = reinterpret_cast<const char* (*)(TPFILE * tpf)>(0x483f10);
static auto TPAccessNextLine = reinterpret_cast<const char* (*)(TPFILE * tpf)>(0x483f90);
static auto TPGetValue = reinterpret_cast<const char* (*)(TPFILE * tpf, const char* label)>(0x483b30);

static auto ConstExpI = reinterpret_cast<void (*)(MUGEN_EVAL_VALUE * eval, int value)>(0x406f20);
static auto ConstExpF = reinterpret_cast<void (*)(MUGEN_EVAL_VALUE * eval, float value)>(0x406fa0);
static auto SCtrlReadExpList = reinterpret_cast<int (*)(const char* value, const char* format, MUGEN_PLAYER_INFO * playerInfo, const char** parseEnd, ...)>(0x47d780);
static auto SCtrlReadExpListArray = reinterpret_cast<int (*)(const char params, const char* format, MUGEN_PLAYER_INFO * playerInfo, const char** parseEnd, void* evaltype, void* evallist, int* numTrigChars, DWORD param8)>(0x47D980);

static auto GetQuotedString = reinterpret_cast<int (*)(TPFILE * tpf, const char* label, const char* dest, int size, int zero)>(0x415df0);
static auto ParseSpecialFlag = reinterpret_cast<int (*)(const char* flagStr, MUGEN_ASSERT_SPECIAL_TYPE * asType, MUGEN_ASSERT_SPECIAL_ID * asID)> (0x46aa60);
static auto ParsePosType = reinterpret_cast<int (*)(const char* postypeStr)>(0x47db40);

static auto EvalExpression = reinterpret_cast<MUGEN_EVAL_TYPE(*)(MUGEN_PLAYER * player, MUGEN_EVAL_VALUE * eval, int32_t * pInt, float* pFloat)>(0x407780);
static auto FreeExpression = reinterpret_cast<void (*)(MUGEN_EVAL_VALUE * eval)>(0x406e00);

static auto SCtrlParseTrigger = reinterpret_cast<int (*)(const char* s, MUGEN_PLAYER_INFO * playerInfo, MUGEN_EVAL_TRIGGER * triggers, MUGEN_EVAL_TYPE * types, int maxLength, const char** endptr)>(0x477920);
static auto SCtrlParseElemType = reinterpret_cast<bool (*)(TPFILE * tpf, MUGEN_SC_DATA_EX * sinfo, MUGEN_PLAYER_INFO * playerInfo)>(0x46aa60);
static auto SCtrlRCElemFree = reinterpret_cast<void (*)(MUGEN_SC_DATA_EX * sinfo)>(0x4718d0);
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

#define _NALLEG40
#ifndef _NALLEG40

/**
 * 申し訳程度のAllegro系グローバル変数 + 関数の定義
 * allegro.hと併用する or 手元にalleg40.libを用意できない場合は_NALLEG40マクロを定義してパスして下さい.
 */

/* Allegro global data */
__declspec(dllimport) int32_t _rgb_r_shift_16;
__declspec(dllimport) int32_t _rgb_g_shift_16;
__declspec(dllimport) int32_t _rgb_b_shift_16;

/* Allegro functions */
__declspec(dllimport) int32_t makecol(int32_t red, int32_t green, int32_t blue);

#endif  // _NALLEG40

/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */
/* ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ */

#endif  // __MUGEN_H__
