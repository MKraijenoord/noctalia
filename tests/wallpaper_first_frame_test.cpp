#include "shell/wallpaper/wallpaper_instance.h"
#include "test_check.h"

int main() {
  {
    WallpaperInstance instance;
    instance.currentPath = "/wallpapers/startup.png";
    TEST_CHECK(showsSettledWallpaper(instance));
  }
  {
    WallpaperInstance instance;
    instance.loadingPath = "/wallpapers/startup.png";
    TEST_CHECK(!showsSettledWallpaper(instance));
  }
  {
    WallpaperInstance instance;
    instance.currentPath = "/wallpapers/startup.png";
    instance.transitioning = true;
    TEST_CHECK(!showsSettledWallpaper(instance));
  }
  return 0;
}
