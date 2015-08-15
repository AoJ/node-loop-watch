{
  "targets": [
    {
      "target_name": "nodelo",
      "sources": [ "/src/nodelo.cc" ],
      "cflags_cc" : ["-fexceptions"],
      "include_dirs" : [
          "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
