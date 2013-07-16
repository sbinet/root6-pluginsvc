pluginsvc
=========

Testing with ``hwaf``:

```sh
$ hwaf init work
$ hwaf setup work
$ cd work
$ hwaf pkg co git://github.com/hwaf/hwaf-tests-pkg-settings pkg-settings
$ hwaf pkg co git://github.com/sbinet/root6-pluginsvc pluginsvc

$ hwaf configure
$ hwaf
```

