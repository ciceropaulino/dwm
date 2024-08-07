/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int gappx = 10;   /* gaps between windows */
static const unsigned int snap = 32;    /* snap pixel */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */
static const int horizpadbar = 2;       /* horizontal padding for statusbar */
static const int vertpadbar = 10;       /* vertical padding for statusbar */
static const char *fonts[] = {
    "SFMono Nerd Font "
    "Mono:style=Regular:pixelsize=16:antialias=true:autohint=true",
    "Phosphor-Fill:style=Fill:pixelsize=20:antialias=true:autohint=true"};
static const char dmenufont[] = "monospace:size=10";
// delete this after delete dmenu
static const char col_gray1[] = "#000000"; /*black bg normal mod*/
static const char col_gray2[] = "#000000"; /*black bg border*/
static const char col_gray3[] = "#444444";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#ff0000"; /*red bg selctor and selected
// window*/
//  static const unsigned int baralpha = 0xd0;
static const unsigned int baralpha = 0x00U;     /*alpha patch variables*/
static const unsigned int borderalpha = OPAQUE; /*alpha patch variables*/

#include "colors/cccp_dark.h"

// static const char *colors[][3] = {
/*               fg         bg         border   */
//    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
//    [SchemeSel] = {col_gray4, col_gray1, col_cyan},
//};

static const unsigned int alphas[][3] = {
    /*               fg      bg        border*/
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
};

static const char *const autostart[] = {
    "zsh", "/home/comrade/.autostart_dwm.sh", NULL /* terminate */
};

/* tagging */
// static const char *tags[] = {"", "2", "3", "4", "5", "6", "7", "8", "9"};
static const char *tags[] = {"", "", "", "", "",
                             "", "", "", ""};

static const unsigned int ulinepad =
    5; /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke =
    2; /* thickness / height of the underline */
static const unsigned int ulinevoffset =
    0; /* how far above the bottom of the bar the line should appear */
static const int ulineall =
    0; /* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"kitty", NULL, NULL, 1 << 0, 0, 0, -1},
    {"firefox", NULL, NULL, 1 << 5, 0, 0, -1},
    {"Chromium", NULL, NULL, 1 << 5, 0, 0, -1},
    {"discord", NULL, NULL, 1 << 7, 0, 0, -1},
    {"Spotify", NULL, NULL, 1 << 8, 0, 0, -1},
    {"Thunar", NULL, NULL, 1 << 4, 0, 0, -1},
    {"Obsidian", NULL, NULL, 1 << 6, 0, 0, -1},

};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    0; /* 1 will force focus on the fullscreen window */

// static const Layout layouts[] = {
/* symbol     arrange function */
//    {"[]=", tile}, /* first entry is default */
//    {"><>", NULL}, /* no layout function means floating behavior */
//    {"[M]", monocle},
//};

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"   ", tile}, /* first entry is default */
    {"   ", NULL}, /* no layout function means floating behavior */
    {"   ", monocle},
    {"   ", centeredmaster},
    {"   ", centeredfloatingmaster},
    {NULL, NULL},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL};
static const char *termcmd[] = {"kitty", NULL};
static const char *rofi[] = {
    "zsh", "/home/comrade/.config/rofi/launchers/type-7/launcher.sh", NULL};
// static const char *firefox[] = {"firefox", NULL};
static const char *chromium[] = {"chromium", NULL};
static const char *thunar[] = {"thunar", NULL};
static const Key keys[] = {
    /* modifier                     key        function        argument */
    //    {MODKEY, XK_p, spawn, {.v = dmenucmd}},
    {MODKEY, XK_p, spawn, {.v = rofi}},
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = termcmd}},
    {MODKEY | ShiftMask, XK_b, spawn, {.v = chromium}},
    {MODKEY | ShiftMask, XK_f, spawn, {.v = thunar}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_Left, focusdir, {.i = 0}},  // left
    {MODKEY, XK_Right, focusdir, {.i = 1}}, // right
    {MODKEY, XK_Up, focusdir, {.i = 2}},    // up
    {MODKEY, XK_Down, focusdir, {.i = 3}},  // down
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ControlMask, XK_j, pushdown, {0}},
    {MODKEY | ControlMask, XK_k, pushup, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    //{MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_u, setlayout, {.v = &layouts[3]}},
    {MODKEY, XK_o, setlayout, {.v = &layouts[4]}},
    {MODKEY | ControlMask, XK_comma, cyclelayout, {.i = -1}},
    {MODKEY | ControlMask, XK_period, cyclelayout, {.i = +1}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_f, togglefullscreen, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    {MODKEY, XK_minus, setgaps, {.i = -1}},
    {MODKEY, XK_equal, setgaps, {.i = +1}},
    {MODKEY | ShiftMask, XK_equal, setgaps, {.i = 0}},

    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
    {MODKEY | ControlMask | ShiftMask, XK_q, quit, {1}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
