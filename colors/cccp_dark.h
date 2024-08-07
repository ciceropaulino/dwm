static const char total_black[] = "#000000";
static const char mid_gray[] = "#f9f9f9";
static const char light_gray[] = "#fefefe";
static const char dark_gray[] = "#0e0e0e";
static const char cccp_red[] = "#ff0000";
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {mid_gray, total_black, dark_gray},
    [SchemeSel] = {cccp_red, total_black, cccp_red},
};
